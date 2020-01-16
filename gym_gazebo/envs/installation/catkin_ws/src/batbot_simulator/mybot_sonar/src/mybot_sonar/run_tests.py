# %%
# Directionality
#
import Acoustics
import numpy
from matplotlib import pyplot

# %%
# Directionality
#
n = 25

azimuths = numpy.linspace(-90, 90, n)
elevations = numpy.linspace(-30, 30, n)

azimuths, elevations = numpy.meshgrid(azimuths, elevations)
azimuths = azimuths.reshape(n * n)
elevations = elevations.reshape(n * n)
distances = numpy.ones(n * n)

energies = []

for azimuth, elevation, distance in zip(azimuths, elevations, distances):
    azimuth = numpy.array([azimuth])
    elevation = numpy.array([elevation])
    distance = numpy.array([distance])
    result = Acoustics.echo_gen_direct(distance, azimuth, elevation)
    energies.append(result['energy'])

energies = numpy.array(energies)
energies = energies.reshape(n, n)
azimuths = azimuths.reshape(n, n)
elevations = elevations.reshape(n, n)

pyplot.figure()
pyplot.contourf(azimuths, elevations, energies)
pyplot.axis('equal')
pyplot.show()

# %%
# Energy as a function of number of points
#

points = numpy.array(range(100, 500, 10))
energy_levels = []
for n in points:
    print(n)
    azimuths = numpy.linspace(-50, 50, n)
    elevations = numpy.linspace(-50, 50, n)
    distances = numpy.ones(azimuths.shape)
    result = Acoustics.echo_gen_direct(distances, azimuths, elevations)
    energy = result['energy']
    energy_levels.append(energy)

energy_levels = numpy.array(energy_levels)

pyplot.figure()
pyplot.plot(points, energy_levels)
pyplot.show()

pyplot.figure()
pyplot.plot(points, energy_levels / (points ** 1))
pyplot.show()

pyplot.figure()
pyplot.plot(points, energy_levels / (points ** 2))
pyplot.show()

# %%
# Example echoes
#

n = 100

azimuths = (numpy.random.rand(n) * 2 - 1) * 45
elevations = (numpy.random.rand(n) * 2 - 1) * 45
distances = (numpy.random.rand(n) * 5) + 1

result = Acoustics.echo_gen_direct(distances, azimuths, elevations)
Acoustics.plot_echo(result)

# %%
# check out the delays
#
min_delay =  min(result['delays'])
T = 0.001
print("delays",result["delays"], "min delay", min(result['delays']), result['echoes_pa'], len(result['delays']), len(result['echoes_pa'])) 
window_delay = numpy.where(result['delays'] <= min_delay+T )
print(numpy.where(result['delays'] <= min_delay+T ), result['echoes_pa'][window_delay])
windowed_energy = Acoustics.give_energy_windowed(result['echo_sequence'], min(result['delays']))
print("windowed energy", windowed_energy, "energy", result['energy'])