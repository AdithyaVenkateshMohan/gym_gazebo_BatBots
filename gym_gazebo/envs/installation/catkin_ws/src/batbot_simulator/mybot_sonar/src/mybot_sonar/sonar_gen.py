#!/usr/bin/env python


# topic that need to be subcribed is a point cloud /mybot/laser/pointcloud2
# point cloud2 will have the x,y,z which have to be converted into polar co-ordinates
# then given to the sonar signal simlator to get the signal
# this block of code is meant to be written in python 3
#
# 


# importing below required libaries
import rospy 

#import pcl 
from sensor_msgs.msg import PointCloud 
from geometry_msgs.msg import Point 

import sensor_msgs.point_cloud2 as pc2


import numpy
from matplotlib import pyplot
from scipy.interpolate import interp1d
from mybot_sonar import library

import math

Sample_frequency = 250000

#callback on reciving the pointcloud data
def callback(data):
    
    #pc = pc2.read_points(data, skip_nans = True)
    
    pc_list = []
    #for p in pc :
    #    pc_list.append([p[0], p[1], p[2] , p[4]])
    
    pc_list = data.points
    intensity_list = data.channels

    echo_sequence , impulse_time = echo_genration(pc_list)

    pyplot.figure(1)
    pyplot.plot(impulse_time, echo_sequence)
    pyplot.draw()
    pyplot.pause(0.00000002)
    pyplot.clf()
    pyplot.cla()
# debug
i=0
average_values =numpy.array([])

def test_echo_genration_SinglePt(testing_point_genCon , dist_Test = 1 , azi_Test = 0 , ele_Test = 0 ):
    energy_with_dvar = numpy.array([[]])
    energy_with_avar = numpy.array([[]])
    energy_with_evar = numpy.array([[]])
    print("the given testing conditions are ", testing_point_genCon)

    # getting the conditions to generate the points
    if "Dist" in testing_point_genCon :
        r_genCon = testing_point_genCon["Dist"]
        
    else:
        print ("dist must be given in condition")
        
    
    if "Ele" in testing_point_genCon:
        e_genCon = testing_point_genCon["Ele"]
    else :
        print ("Ele must be in the gn condition")
        

    if "Azi" in testing_point_genCon:
        a_genCon = testing_point_genCon["Azi"]
    else:
        print("Azi must be in condition to genrate points")
        
    # conditions that needs to checked 
    assert("Dist" in testing_point_genCon and "Ele" in testing_point_genCon and "Azi" in testing_point_genCon)
    assert(len(r_genCon) == 3 or len(r_genCon) == 1)
    assert(len(e_genCon) == 3 or len(e_genCon) == 1)
    assert(len(a_genCon) == 3 or len(a_genCon) == 1)

    const_dist = numpy.array([dist_Test])
    azi_const = numpy.array([azi_Test])
    ele_const = numpy.array([ele_Test])
    
    if len(r_genCon) > 1:
        distance_var = numpy.arange(r_genCon[0], r_genCon[1], r_genCon[2]) 
        # testing points with varying distances
        for d in distance_var:
            ele = ele_const
            az = azi_const
            dist = numpy.array([d])
            print("point trying out is" , ele , az ,dist)
            echo , time = echo_gen_Direct(dist , az , ele)
            energy = echo_total_energycalulation(echo)
            if not energy_with_dvar.size:
                energy_with_dvar = numpy.array([[energy,dist]])
            else:
                energy_with_dvar = numpy.append(energy_with_dvar , [[energy,dist]] , axis = 0)


    if len(a_genCon) > 1:
        azi_var = numpy.arange(a_genCon[0], a_genCon[1], a_genCon[2])
        #testing points with varying azimuth 
        for a in azi_var:
            ele = ele_const
            az = numpy.array([a])
            dist = const_dist
            print("point trying out is" , ele , az ,dist)
            echo , time = echo_gen_Direct(dist , az , ele)
            energy = echo_total_energycalulation(echo)
            if not energy_with_avar.size:
                energy_with_avar = numpy.array([[energy,az]])
            else:
                energy_with_avar = numpy.append(energy_with_avar , [[energy,az]], axis = 0)

             

    if len(e_genCon) > 1:
        ele_var = numpy.arange(e_genCon[0], e_genCon[1], e_genCon[2])
        #testing points with varying azimuths
        for e in ele_var:
            ele = numpy.array([e])
            az = azi_const
            dist = const_dist
            print("point trying out is" , ele , az ,dist)
            echo , time = echo_gen_Direct(dist , az , ele)
            energy = echo_total_energycalulation(echo)
            if not energy_with_evar.size:
                energy_with_evar = numpy.array([[energy,ele]])
            else:
                energy_with_evar = numpy.append(energy_with_evar , [[energy,ele]] , axis = 0)
        
    return energy_with_dvar , energy_with_avar , energy_with_evar

# not that different from single point test
# just getting the points and returning the energy
def MultiPt_Test_echo_generation(distances , azimuths , elevations):
    # generating the echo with given points
    echo , time = echo_gen_Direct(distances , azimuths , elevations)
    energy = echo_total_energycalulation(echo)

    return energy

    
    
    
    



      


def echo_genration(pc_list):
    #param for the echo generation
    global i 
    
    sample_frequency = 125000
    emission_level = 100
    emission_duration = 0.0025
    emission_frequency = 40000
    emitter_radius = 0.005
    absorption_coefficient = 1.318  # http://www.sengpielaudio.com/calculator-air.htm
    reflection_strength = -40
    speed_of_sound = 340

    #####this is where i can give the input 
    azimuths = numpy.array([])
    elevations = numpy.array([])
    distances = numpy.array([])
    print("single point", pc_list[0],"no of points", len(pc_list))
    for p in pc_list:
        #print(p)
        distances = numpy.append(distances, p.x)
        azimuths = numpy.append(azimuths, math.degrees(p.y))
        elevations = numpy.append(elevations, math.degrees(p.z))
    

    print("most near by dist", numpy.min(distances))

    # if not we didn't recive any points    
    assert(distances.size > 0)


    emission_samples = int(sample_frequency * emission_duration)
    emission_time = numpy.linspace(0, emission_duration, emission_samples)
    emission = numpy.sin(2 * numpy.pi * emission_frequency * emission_time)
    window = library.signal_ramp(emission_samples, 10)
    emission = emission * window

    # pyplot.figure()
    # pyplot.plot(emission)

    # %%
    # Make piston model (model of emitter directionality)

    piston, degrees = library.pistonmodel(emission_frequency, radius=emitter_radius)
    piston = 10 * numpy.log10(piston)
    piston_function = interp1d(degrees, piston)

    # pyplot.figure()
    # pyplot.plot(degrees, piston)

    # %%
    # Get excentricities and echo delays

    excentricities = library.gca(azimuths, elevations, 0, 0)
    # @causing errors is this too  long for 
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

    # pyplot.figure()
    # pyplot.plot(impulse_time, impulse_response)

    # %%
    # Make echo sequence

    echo_sequence = numpy.convolve(emission, impulse_response, mode='same')
   
    global average_values
    print("compare :", average_values , "Vs" ,numpy.array([distances , elevations , azimuths]))
    if(i==0):
        average_values = numpy.array([distances , elevations , azimuths])
        variations = numpy.zeros(numpy.shape(average_values))
    else:
        new_average_values = numpy.array([distances , elevations , azimuths])
        variations = average_values - new_average_values
        if(numpy.any(variations > 0)):
            print("variations there", numpy.where(variations>0 , variations*10, -1))
        average_values = new_average_values
    i+=1
    
    return echo_sequence , impulse_time , variations
def echo_gen_Direct(distances , azimuths , elevations):
    sample_frequency = 125000
    emission_level = 100
    emission_duration = 0.0025
    emission_frequency = 40000
    emitter_radius = 0.005
    absorption_coefficient = 1.318  # http://www.sengpielaudio.com/calculator-air.htm
    reflection_strength = -40
    speed_of_sound = 340

    emission_samples = int(sample_frequency * emission_duration)
    emission_time = numpy.linspace(0, emission_duration, emission_samples)
    emission = numpy.sin(2 * numpy.pi * emission_frequency * emission_time)
    window = library.signal_ramp(emission_samples, 10)
    emission = emission * window

    piston, degrees = library.pistonmodel(emission_frequency, radius=emitter_radius)
    piston = 10 * numpy.log10(piston)
    piston_function = interp1d(degrees, piston)

    # pyplot.figure()
    # pyplot.plot(degrees, piston)

    # %%
    # Get excentricities and echo delays

    excentricities = library.gca(azimuths, elevations, 0, 0)
    # @causing errors is this too  long for 
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

    # pyplot.figure()
    # pyplot.plot(impulse_time, impulse_response)

    # %%
    # Make echo sequence
    echo_sequence = numpy.convolve(emission, impulse_response, mode='same')

    return echo_sequence, impulse_time

def echo_genration_for_observation(pc_list):
    #param for the echo generation
    global i 
    

    #####this is where i can give the input 
    azimuths = numpy.array([])
    elevations = numpy.array([])
    distances = numpy.array([])
    print("single point", pc_list[0],"no of points", len(pc_list))
    for p in pc_list:
        #print(p)
        distances = numpy.append(distances, p.x)
        azimuths = numpy.append(azimuths, math.degrees(p.y))
        elevations = numpy.append(elevations, math.degrees(p.z))
    

    print("most near by dist", numpy.min(distances))

    # if not we didn't recive any points    
    assert(distances.size > 0)

    echo_sequence , impulse_time = echo_gen_with_ears(distances , azimuths , elevations)

    return echo_sequence , impulse_time 

# this fucntion is made for to be called to generate echo signals for the two ears of the robot
def echo_gen_with_ears(distances , azimuths , elevations):
    # this for simulating the directionality between the ears
    # adding and substracting to azimuths based on the ears
    # this means the left ear gives more preference to points on left than that of right and viceversa for rightear
    left_azimuth = azimuths + 0
    right_azimuth = azimuths - 0
    sample_frequency = 125000
    emission_level = 100
    emission_duration = 0.0025
    emission_frequency = 40000
    emitter_radius = 0.005
    absorption_coefficient = 1.318  # http://www.sengpielaudio.com/calculator-air.htm
    reflection_strength = -40
    speed_of_sound = 340

    emission_samples = int(sample_frequency * emission_duration)
    emission_time = numpy.linspace(0, emission_duration, emission_samples)
    emission = numpy.sin(2 * numpy.pi * emission_frequency * emission_time)
    window = library.signal_ramp(emission_samples, 10)
    emission = emission * window

    piston, degrees = library.pistonmodel(emission_frequency, radius=emitter_radius)
    piston = 10 * numpy.log10(piston)
    piston_function = interp1d(degrees, piston)

    # pyplot.figure()
    # pyplot.plot(degrees, piston)

    # %%
    # Get excentricities and echo delays

    excentricities_left  = library.gca(left_azimuth, elevations, 0, 0)
    excentricities_right  = library.gca(right_azimuth, elevations, 0, 0)
    # @causing errors is this too  long for 
    delays = 2 * distances / speed_of_sound

    # %%
    # Calculate path losses
    loss_directionality_left = piston_function(excentricities_left)
    loss_directionality_right = piston_function(excentricities_right)
    loss_attenuation = - 2 * distances * absorption_coefficient
    loss_spreading = -40 * numpy.log10(distances)

    echoes_left = emission_level + reflection_strength + loss_directionality_left + loss_attenuation + loss_spreading
    echoes_right = emission_level + reflection_strength + loss_directionality_right + loss_attenuation + loss_spreading
    echoes_pa_l = library.db2pa(echoes_left)
    echoes_pa_l[echoes_left < 0] = 0

    echoes_pa_r = library.db2pa(echoes_right)
    echoes_pa_r[echoes_right < 0] = 0


    # %%
    # Make impulse response
    impulse_time_l, impulse_response_l = library.make_impulse_response(delays, echoes_pa_l, emission_duration, sample_frequency)
    impulse_time_r, impulse_response_r = library.make_impulse_response(delays, echoes_pa_r, emission_duration, sample_frequency)

    # pyplot.figure()
    # pyplot.plot(impulse_time, impulse_response)

    # %%
    # Make echo sequence
    echo_sequence_l = numpy.convolve(emission, impulse_response_l, mode='same')
    echo_sequence_r = numpy.convolve(emission, impulse_response_r, mode='same')

    echo_sequence = (echo_sequence_l , echo_sequence_r)

    return echo_sequence, impulse_time_l


def echo_total_energycalulation(echo):
    return numpy.sum(numpy.power(echo,2))

# not yet defined 
def echo_time_window_energycalulation(echo , time_window):
    global Sample_frequency
    window_size = int(time_window * Sample_frequency)
    windowed_energy = numpy.array([])
    echo = numpy.power(echo,2)
    for i in range(len(echo)):
        if window_size+ i < len(echo)-1:
            single_window = numpy.sum(echo[i:i+window_size])
        else:
            single_window = numpy.sum(echo[i:len(echo)])

        windowed_energy = numpy.append(windowed_energy, single_window)
    return windowed_energy


def listener3d():
    #creates  a node called peeker to process the 
    
    pyplot.show()
    pyplot.ion()
    rospy.init_node("peeker", anonymous = True)
    #subscribing to the pointcloud data which is published  
    rospy.Subscriber("/mybot/laser/polorcloud", PointCloud, callback)
    rospy.spin() #keeps the python from exciting until the node stopped



if __name__ == "__main__":
    try:
        listener3d()
    except rospy.ROSInterruptException:
        pass



    
    