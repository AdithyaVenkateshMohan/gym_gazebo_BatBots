import warnings
import numpy
import scipy.special as special
from matplotlib import pyplot
from scipy.interpolate import interp1d
from scipy.signal import windows, chirp
from scipy.ndimage.filters import gaussian_filter1d as gaussian


def make_impulse_response(delays, echoes_pa, emission_duration, fs):
    duration = numpy.max(delays) + emission_duration
    impulse_time = numpy.arange(0, duration, 1 / fs)
    impulse_response = numpy.zeros(len(impulse_time))
    corrected_delays = delays + emission_duration / 2
    indices = []
    for amplitude, delay in zip(echoes_pa, corrected_delays):
        index = numpy.argmin(numpy.abs(impulse_time - delay))
        impulse_response[index] = impulse_response[index] + amplitude
        indices.append(index)
    return_value = {}
    return_value['impulse_time'] = impulse_time
    return_value['impulse_response'] = impulse_response
    return_value['indices'] = numpy.array(indices)
    return return_value


def gca(azimuth1, elevation1, azimuth2, elevation2):
    azimuth1 = numpy.deg2rad(azimuth1)
    elevation1 = numpy.deg2rad(elevation1)
    azimuth2 = numpy.deg2rad(azimuth2)
    elevation2 = numpy.deg2rad(elevation2)

    term1 = numpy.sin(elevation1) * numpy.sin(elevation2)
    term2 = numpy.cos(elevation1) * numpy.cos(elevation2)
    term3 = numpy.cos(numpy.abs(azimuth1 - azimuth2))

    d = numpy.arccos(term1 + term2 * term3)
    d = numpy.rad2deg(d)
    return d


def pistonmodel(freq, radius=0):
    pi = numpy.pi
    angles = numpy.linspace(-pi / 2, pi / 2, 100)
    if radius == 0: radius = 0.014
    wavelength = 340.29 / freq
    K = 2 * pi / wavelength
    Z = K * (radius * numpy.sin(angles))
    T = 2 * special.jv(1, Z)
    N = K * radius * numpy.sin(angles)
    P = numpy.abs(T / N)
    I = P ** 2
    degrees = numpy.rad2deg(angles)
    return I, degrees


def db2ratio(db):
    db = numpy.array(db, dtype='f')
    db = db.astype(float)
    ratio = 10 ** (db / 20.0)
    return ratio


def db2pa(db):
    # see http://www.sengpielaudio.com/TableOfSoundPressureLevels.htm
    reference_value = 2.0 * 10 ** -5
    min_value = numpy.min(db)
    if min_value < 0: warnings.warn("db2pa function should not be used with negative values!")
    db = db.astype(float)
    return db2ratio(db) * reference_value


def pa2db(pa):
    reference_value = 2.0 * 10 ** -5
    pa = pa.astype(float)
    pa[pa < reference_value] = reference_value
    return 20 * numpy.log10(pa / (2.0 * 10 ** -5))


def signal_ramp(n, percent):
    if percent > 49: percent = 49
    length = int(numpy.floor((n * percent) / 100))
    window = windows.hamming(length * 2 + 1)
    window = window - numpy.min(window)
    window = window / numpy.max(window)
    left = window[0:length + 1]
    right = window[length:]
    buffer = numpy.ones(n - 2 * left.size)
    total = numpy.hstack((left, buffer, right))
    return total


def echo_gen_direct(distances, azimuths, elevations, sample_frequency=250000):
    emission_level = 100
    emission_duration = 0.0025
    emission_frequency = 40000
    emitter_radius = 0.005
    absorption_coefficient = 1.318  # http://www.sengpielaudio.com/calculator-air.htm
    reflection_strength = -20
    speed_of_sound = 340
    noise_floor = 20

    emission_samples = int(sample_frequency * emission_duration)
    emission_time = numpy.linspace(0, emission_duration, emission_samples)
    emission = numpy.sin(2 * numpy.pi * emission_frequency * emission_time)
    #emission = chirp(emission_time, f0=50000, f1=25000, t1=emission_duration, method='quadratic')
    emission_window = signal_ramp(emission_samples, 10)
    emission = emission * emission_window

    # %%
    # Calculate directivity
    piston, degrees = pistonmodel(emission_frequency, radius=emitter_radius)
    piston = 10 * numpy.log10(piston)
    piston_function = interp1d(degrees, piston)
    excentricity = gca(azimuths, elevations, 0, 0)
    delays = 2 * distances / speed_of_sound
    loss_directionality = piston_function(excentricity)

    # %%
    # Calculate path losses
    loss_attenuation = - 2 * distances * absorption_coefficient
    loss_spreading = -40 * numpy.log10(distances)

    echoes = emission_level + reflection_strength + loss_directionality + loss_attenuation + loss_spreading
    echoes_pa = db2pa(echoes)
    echoes_pa[echoes < noise_floor] = 0 #noise floor

    # %%
    # Make impulse response and echo sequence
    impulse_result = make_impulse_response(delays, echoes_pa, emission_duration, sample_frequency)
    impulse_response = impulse_result['impulse_response']
    impulse_time = impulse_result['impulse_time']
    impulse_indices = impulse_result['indices']
    echo_sequence = numpy.convolve(emission, impulse_response, mode='same')

    # Get energy
    # Make impulse response and echo sequence
    energy = 0
    echo_window = numpy.zeros(len(impulse_time))
    windowed_echo_sequence = numpy.zeros(len(impulse_time))
    # If we have echoes...
    detectable = impulse_indices[echoes > noise_floor]
    if len(detectable) > 0:
        first_echo_index = numpy.min(detectable)
        echo_window[first_echo_index] = 1
        echo_window = numpy.convolve(emission_window, echo_window, mode='same')
        windowed_echo_sequence = echo_sequence * echo_window
        energy = numpy.sum(windowed_echo_sequence ** 2)

    # %% prepare return value
    return_value = {}
    return_value['emission_samples'] = emission_samples
    return_value['delays'] = delays
    return_value['echoes'] = echoes
    return_value['echoes_pa'] = echoes_pa
    return_value['loss_directionality'] = loss_directionality
    return_value['loss_attenuation'] = loss_attenuation
    return_value['loss_spreading'] = loss_spreading
    return_value['echo_sequence'] = echo_sequence
    return_value['impulse_result'] = impulse_result
    return_value['echo_window'] = echo_window
    return_value['windowed_echo_sequence'] = windowed_echo_sequence
    return_value['energy'] = energy
    return return_value




def plot_echo(return_value):
    emission_samples = return_value['emission_samples']
    delays = return_value['delays']
    echo_window = return_value['echo_window']
    echo_sequence = return_value['echo_sequence']
    windowed_echo_sequence = return_value['windowed_echo_sequence']
    impulse_time = return_value['impulse_result']['impulse_time']
    impulse_response = return_value['impulse_result']['impulse_response']

    impulse_response_db = pa2db(impulse_response)
    max_value = numpy.max(numpy.abs(echo_sequence))

    low_pass = gaussian(impulse_response_db, int(emission_samples/2))
    low_pass = (low_pass/ numpy.max(low_pass)) * numpy.max(impulse_response_db)

    pyplot.figure()
    pyplot.subplot(3, 1, 1)
    pyplot.plot(impulse_time, impulse_response_db)
    pyplot.plot(impulse_time, low_pass)
    pyplot.title('Impulse response')
    pyplot.xlabel('Time')
    pyplot.ylabel('dB_spl')

    pyplot.subplot(3, 1, 2)
    pyplot.plot(impulse_time, echo_sequence)
    pyplot.vlines(delays, -max_value, max_value, 'red')
    pyplot.title('Echo Sequence')
    pyplot.xlabel('Time')
    pyplot.ylabel('Pa')

    pyplot.subplot(3, 1, 3)
    pyplot.plot(impulse_time, windowed_echo_sequence)
    pyplot.plot(impulse_time, echo_window * max_value, 'green')
    pyplot.title('Windowed echo')
    pyplot.xlabel('Time')
    pyplot.ylabel('Pa')

    pyplot.show()



def echo_genration_for_observation(pc_list):
    #param for the echo generation
    global i 
    

    #####this is where i can give the input 
    azimuths = numpy.array([])
    elevations = numpy.array([])
    distances = numpy.array([])
    #print("single point", pc_list[0],"no of points", len(pc_list))
    for p in pc_list:
        #print(p)
        distances = numpy.append(distances, p.x)
        azimuths = numpy.append(azimuths, math.degrees(p.y))
        elevations = numpy.append(elevations, math.degrees(p.z))
    

    #print("most near by dist", numpy.min(distances))

    # if not we didn't recive any points    
    assert(distances.size > 0)

    echo_sequence , impulse_time = echo_gen_with_ears(distances , azimuths , elevations)


def give_energy_windowed(echo_seq , start_time, sample_frequency = 125000, fixed_T = 0.001):
    start_index = int(start_time*sample_frequency)
    T = int(fixed_T*sample_frequency)
    if len(echo_seq) < start_index :
        return 0
    
    if len(echo_seq) >= start_index+T+1:
        end = start_index+T+1
    else :
        end = len(echo_seq)

        
    
    energy = np.sum(np.pow(echo_seq[start_index:end],2))

    return energy





    # this fucntion is made for to be called to generate echo signals for the two ears of the robot
def echo_gen_with_ears(distances , azimuths , elevations , obs_type = "echo" , debug = False):
    # this for simulating the directionality between the ears
    # adding and substracting to azimuths based on the ears
    # this means the left ear gives more preference to points on left than that of right and viceversa for rightear
    left_azimuth = azimuths + 10
    right_azimuth = azimuths - 10
    
    echo_left = echo_gen_direct(distances, left_azimuth , elevations, sample_frequency= 125000)
    echo_right = echo_gen_direct(distances, right_azimuth , elevations, sample_frequency= 125000)

    if obs_type == "echo"
        echo_sequence_l = echo_left["echo_sequence"]
        echo_sequence_r = echo_right["echo_sequence"]
        impulse_time_l = echo_left['impulse_result']['impulse_response']
        echo_sequence = (echo_sequence_l , echo_sequence_r)
        return echo_sequence, impulse_time_l
    
    if obs_type == "energyies"
        min_left_delay = min(echo_left["delays"])
        min_right_delay = min(echo_right["delays"])
        most_min_delay = min((min_left_delay,min_right_delay))


        
        impulse_time_l = echo_left['impulse_result']['impulse_response']
        impulse_time_r = echo_left['impulse_result']['impulse_response']

        


