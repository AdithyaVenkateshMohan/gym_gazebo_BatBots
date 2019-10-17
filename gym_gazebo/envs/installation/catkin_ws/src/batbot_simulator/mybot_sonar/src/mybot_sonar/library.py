import warnings

import numpy
from scipy import special as special
from scipy.signal import windows


def make_impulse_response(delays,echoes_pa,emission_duration, fs):
    duration = numpy.max(delays)
    # addded dtype to float 32 to reduce the memory usage
    #impulse_time = numpy.arange(0, duration, 1 / fs , dtype=numpy.dtype('f4'))
    impulse_time = numpy.linspace(0 , duration, duration*fs)
    #print impulse_time , duration/fs , duration , fs
    impulse_response = numpy.zeros(len(impulse_time))
    corrected_delays = delays + emission_duration / 2
    for amplitude, delay in zip(echoes_pa, corrected_delays):
        index = numpy.argmin(numpy.abs(impulse_time - delay))
        impulse_response[index] = impulse_response[index] + amplitude
    return impulse_time, impulse_response


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
    min_value = numpy.min(db)
    if min_value < 0: warnings.warn("db2pa function should not be used with negative values!")
    db = db.astype(float)
    return db2ratio(db) * (2.0 * 10 ** -5)


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