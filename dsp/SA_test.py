from SkippingAverage import SkippingAverage
import matplotlib.pyplot as plt
from random import random
from scipy import signal
import numpy as np

# =================

sampling_rate = 5000

pwm_freq = 1000
amplitude = 800

noise_p2p = 30
noise_floor = 50

cycles = 1

# =================

end_time = 1/pwm_freq * cycles

t = np.linspace(0, end_time, sampling_rate, endpoint=False)
sig = amplitude/2 + amplitude/2 * signal.square(2 * np.pi * pwm_freq * t)


s8 = SkippingAverage(3, noise_floor)
sma = SkippingAverage(5, 0, simple=True)
savg8 = []
avg = []

# add noise to signal
for (i, sample) in enumerate(sig):
	sig[i] = sample + random() * noise_p2p

# build moving averages
for sample in sig:
	savg8.append(s8.out(int(sample)))
	avg.append(sma.out(int(sample)))

fig, axs = plt.subplots(2)
fig.suptitle('Signal Analysis with Noise')
axs[0].plot(t, sig)
axs[1].plot(t, savg8)

#plt.ylim(-1, amplitude + 1)
plt.show()
