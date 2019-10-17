
import numpy
from matplotlib import pyplot
from scipy.interpolate import interp1d
import library


# Settings

sample_frequency = 250000
emission_level = 100
emission_duration = 0.0025
emission_frequency = 40000
emitter_radius = 0.005
absorption_coefficient = 1.318  # http://www.sengpielaudio.com/calculator-air.htm
reflection_strength = -40
speed_of_sound = 340

# Input

azimuths = numpy.array([30, 0, 45, 0])
elevations = numpy.array([30, 0, 30, 0])
distances = numpy.array([1, 2, 3, 10])

# %%
# Make emission signal

emission_samples = int(sample_frequency * emission_duration)
emission_time = numpy.linspace(0, emission_duration, emission_samples)
emission = numpy.sin(2 * numpy.pi * emission_frequency * emission_time)
window = library.signal_ramp(emission_samples, 10)
emission = emission * window

pyplot.figure()
pyplot.plot(emission)

# %%
# Make piston model (model of emitter directionality)

piston, degrees = library.pistonmodel(emission_frequency, radius=emitter_radius)
piston = 10 * numpy.log10(piston)
piston_function = interp1d(degrees, piston)

pyplot.figure()
pyplot.plot(degrees, piston)

# %%
# Get excentricities and echo delays

excentricities = library.gca(azimuths, elevations, 0, 0)
delays = 2 * distances / speed_of_sound

# %%
# Calculate path losses

loss_directionality = piston_function(excentricities)
loss_attenuation = - 2 * distances * absorption_coefficient
loss_spreading = -40 * numpy.log10(distances)

echoes = emission_level + reflection_strength + loss_directionality + loss_attenuation + loss_spreading
echoes_pa = library.db2pa(echoes)
echoes_pa[echoes < 0] = 0

# %%
# Make impulse response

impulse_time, impulse_response = library.make_impulse_response(delays, echoes_pa, emission_duration, sample_frequency)

pyplot.figure()
pyplot.plot(impulse_time, impulse_response)

# %%
# Make echo sequence

echo_sequence = numpy.convolve(emission, impulse_response, mode='same')

pyplot.figure()
pyplot.plot(impulse_time, echo_sequence)

pyplot.show()
