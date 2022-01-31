class SkippingAverage:
	def __init__(self, bit_size, noise_floor, simple=False):
		self.bit_size = bit_size
		self.size = 1 << bit_size # 2^n
		self.noise_floor = noise_floor
		
		self.data = [0] * self.size
		self.average = 0

		self.simple_sma = simple

	def out(self, sample):
		# skip samples that are less than the noise
		if sample <= self.noise_floor and not self.simple_sma:
			return self.average >> self.bit_size

		self.data.append(sample)

		#if len(self.data) == self.size + 1:
		victim = self.data.pop(0)
		self.average -= victim

		self.average += sample

		return self.average >> self.bit_size
