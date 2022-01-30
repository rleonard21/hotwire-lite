class SkippingAverage:
	def __init__(self, bit_size):
		self.bit_size = bit_size
		self.size = 1 << bit_size # 2^n
		
		self.data = [0] * self.size
		self.average = 0

	def out(self, sample):
		self.data.append(sample)

		if len(self.data) == self.size + 1:
			victim = self.data.pop(0)
			self.average -= victim

		self.average += sample

		return self.average >> self.bit_size
