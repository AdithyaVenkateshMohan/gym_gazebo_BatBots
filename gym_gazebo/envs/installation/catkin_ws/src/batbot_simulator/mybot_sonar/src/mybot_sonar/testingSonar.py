#/usr/bin/python
# script is written to test the sonar_gen with testing points
import sonar_gen
from matplotlib import pyplot as plt
import numpy as np
from mpl_toolkits.mplot3d import axes3d, Axes3D #<-- Note the capitalization! 



"""
To generate 'num' points on a sphere of radius 'r' centred on the origin
- Random placement involves randomly chosen points for 'z' and 'phi'
- Regular placement involves chosing points such that there one point per d_area

References:
Deserno, 2004, How to generate equidistributed points on the surface of a sphere
http://www.cmu.edu/biolphys/deserno/pdf/sphere_equi.pdf
"""

import random
import math
from pprint import pprint

def random_on_sphere_points(r,num):
	points = []
	for i in range(0,num):
		z =  random.uniform(-r,r) 
		phi = random.uniform(0,2*math.pi)
		x = math.sqrt(r**2 - z**2)*math.cos(phi)
		y = math.sqrt(r**2 - z**2)*math.sin(phi)
		points.append([x,y,z])
	return points

# convex from observer
def regular_on_sphere_points(r, num , conditions = None):
	points = np.array([])
	#Break out if zero points
	if num==0:
		return points

	a = 4.0 * math.pi*(r**2.0 / num)
	d = math.sqrt(a)
	m_theta = int(round(math.pi / d))
	d_theta = math.pi / m_theta
	d_phi = a / d_theta

	for m in range(0,m_theta):
		theta = math.pi * (m + 0.5) / m_theta
		m_phi = int(round(2.0 * math.pi * math.sin(theta) / d_phi))
		for n in range(0,m_phi):
			phi = 2.0 * math.pi * n / m_phi
			if(n == 0 and m ==0):
				points = np.array([[r,phi,theta]])
			else:			
				points = np.append(points,np.array([[r,phi,theta]]), axis =0)
	return points

def generate_points_plane(boundingBox , centre , distance , resolution):
    # getting the width and length of the plane to be generated
    l = boundingBox[0]
    b = boundingBox[1]
    # getting the relative postions with respect to the emitter
    # this centre point on the plane is considered to in line of the emitter intially 
    # it's then translated according to cx , cy
    

    cx = centre[0]
    cy = centre[1]
    # distance 
    assert(distance >0)
    d = distance
    #resolution vr hr 
    vr = resolution[0]
    hr = resolution[1]
    print("no of points to be generated", (l/hr * b/vr))
    elev = 0
    points = np.array([[d ,0 , 0]])
    i = vr
    j = hr
    while i <= b/2:
        while j <= l/2:
            az = math.degrees(math.atan2(j,d))
            points = np.append(points ,[[d , az , elev],[d , az , -elev], [d , -az , elev], [d , -az , -elev] ], axis =0)
            j+=hr
        i+=vr
        j=hr
        elev = math.degrees(math.atan2(i,d))
        #print(elev)
        d = d / math.cos(math.radians(elev))
        points = np.append(points, [[d , 0 , elev] , [d , 0 , -elev]], axis =0)

    return points

            

    









if __name__ == "__main__":
    #TestingCon ={"Dist":[1,5.1,.1], "Ele":[-math.pi/2,math.pi/2,math.pi/180], "Azi":[-math.pi/3,math.pi/3,math.pi/180]}
    # TestingCon ={"Dist":[1,5.1,.1], "Ele":[-90,90,1], "Azi":[-90,90,1]}
    # d , a , e  = sonar_gen.test_echo_genration_SinglePt(TestingCon)
    # print(d[:,0] , d[:,1] , d)
    # if d.size:
    #     plt.figure(1)
    #     plt.title("\t -----Single Point Test---- \n the energy variations with Distance")
    #     plt.xlabel("Distance")
    #     plt.ylabel("Energy")
    #     plt.plot(d[:,1], d[:,0])
    # if a.size:
    #     plt.figure(2)
    #     plt.title('\t -----Single Point Test---- \n the energy variations with Azimuth')
    #     plt.xlabel('Azimuth')
    #     plt.ylabel('Energy')
    #     plt.plot(a[:,1], a[:,0])
    
    # if e.size:
    #     plt.figure(3)
    #     plt.title('\t -----Single Point Test---- \n the energy variations with Elevation')
    #     plt.xlabel('Elevation')
    #     plt.ylabel('Energy')
    #     plt.plot(e[:,1], e[:,0])
    
    # radius = 3
    # points = 1000

    print("Evenly distributed points")
    regular_surf_points = generate_points_plane([1,1], [2,2], 2 ,[0.1,0.1])
    print("generated sphere points",regular_surf_points, np.shape(regular_surf_points))

    fig = plt.figure()
    ax = Axes3D(fig)
    R = regular_surf_points[:,0]
    PHI = np.radians(regular_surf_points[:,2])
    THETA = np.radians(regular_surf_points[:,1])

    X = R * np.sin(PHI) * np.cos(THETA)
    Y = R * np.sin(PHI) * np.sin(THETA)
    Z = R * np.cos(PHI)

    print(X.shape , Y.shape , Z.shape)

    # Plot the surface.
    ax.plot_trisurf(X, Y, Z, cmap=plt.cm.YlGnBu_r)

    # Tweak the limits and add latex math labels.
    ax.set_xlabel(r'$\phi_\mathrm{real}$')
    ax.set_ylabel(r'$\phi_\mathrm{im}$')
    ax.set_zlabel(r'$V(\phi)$')

    plt.show()


    energy = sonar_gen.MultiPt_Test_echo_generation(regular_surf_points[:,0], regular_surf_points[:,2], regular_surf_points[:,1] )
    print("the energy of the test convex sphere echo is ", energy)

    energyWnum = np.array([])
    Num = np.array([])
    condition = [0.01 , 0.5]
    mul = 0.0003
    c = condition[0]
    while c <= condition[1]:
        regular_surf_points = generate_points_plane([2,2], [2,2], 2 ,[c,c])
        c+=mul
        Num = np.append(Num , np.shape(regular_surf_points)[0])
        energy = sonar_gen.MultiPt_Test_echo_generation(regular_surf_points[:,0], regular_surf_points[:,2], regular_surf_points[:,1] )
        print("numer of points given",  np.shape(regular_surf_points)[0] , "energy of the sonar",energy)
        energyWnum = np.append(energyWnum , energy)
    
    fig2 = plt.figure(2)
    plt.title("energy varx with input resolution")
    plt.xlabel("num of points")
    plt.ylabel("energy")
    plt.plot(Num, energyWnum)




    plt.show()

