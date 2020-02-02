import numpy
from scipy.signal import butter, lfilter, convolve

class Cochlea:
     def __init__(self, fs):
         low_cut = 39000
         high_cut = 42000
         cut_off = 1000
         self.b_bp, self.a_bp = butter_bandpass(low_cut, high_cut, fs,
order=2)
         self.b_lp, self.a_lp = butter_lowpass(cut_off, fs, order=2)
         self.ir = gammatone_ir(fs, 40000)

     def bandpass_filter(self, signal):
         y = lfilter(self.b_bp, self.a_bp, signal)
         return y

     def lowpass_filter(self, signal):
         y = lfilter(self.b_lp, self.a_lp, signal)
         return y

     def gammatone_filter(self, signal):
         y = convolve(signal, self.ir, mode='same')
         return y

     def run(self, signal):
         bandpass_filtered = self.bandpass_filter(signal)
         gamma_filtered = self.gammatone_filter(bandpass_filtered)
         gamma_filtered[gamma_filtered < 0] = 0
         compressed = numpy.power(gamma_filtered, 0.4)
         lowpass_filtered = self.lowpass_filter(compressed)
         lowpass_filtered[lowpass_filtered < 0] = 0
         lowpass_filtered = lowpass_filtered * 150000
         return lowpass_filtered


def butter_lowpass(cutoff, fs, order=5):
     nyq = 0.5 * fs
     normal_cutoff = cutoff / nyq
     b, a = butter(order, normal_cutoff, btype='low', analog=False)
     return b, a


def butter_lowpass_filter(data, cutoff, fs, order=5):
     b, a = butter_lowpass(cutoff, fs, order=order)
     y = lfilter(b, a, data)
     return y


def butter_bandpass(low_cut, high_cut, fs, order=5):
     nyq = 0.5 * fs
     low = low_cut / nyq
     high = high_cut / nyq
     b, a = butter(order, [low, high], btype='band')
     return b, a


def butter_bandpass_filter(data, low_cut, high_cut, fs, order=5):
     b, a = butter_bandpass(low_cut, high_cut, fs, order=order)
     y = lfilter(b, a, data)
     return y


def gammatone_ir(fs, f):
     n = 4
     dt = 1 / fs
     t = numpy.arange(0, 0.0005, dt)
     b = 24.7 * (4.37 * (f / 1000) + 1) * 1.019
     ir = t ** (n - 1) * numpy.exp(-2 * numpy.pi * b * t) * numpy.cos(2
* numpy.pi * f * t)
     return ir


if __name__ == '__main__':
     fs = 300000
     data = numpy.load('000043.npy')
     signal = data[:, 0]
     c = Cochlea(fs)
     result = c.run(signal)