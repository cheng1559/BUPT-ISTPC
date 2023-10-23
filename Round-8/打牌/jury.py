class Queue:
	def __init__(self, sz):
		self.items = [None] * (sz + 1)
		self.head = 0
		self.tail = 0
		self.stat = [1] * 6
		self.prod = 1
	
	def push(self, n):
		if (self.head + 1) % len(self.items) == self.tail:
			self._pop() # Maintain fixed size queue
		self.items[self.head] = n
		self.head = (self.head + 1) % len(self.items)
		self.prod = self.prod // self.stat[n] * (self.stat[n] + 1)
		self.stat[n] += 1

	def _pop(self):
		n = self.items[self.tail]
		self.prod = self.prod // self.stat[n] * (self.stat[n] - 1)
		self.stat[n] -= 1
		self.tail = (self.tail + 1) % len(self.items)

d = 0
n, q = map(int, input().split())
qu = Queue(q)
for _ in range(n):
	z = int(input())
	x = (d + z) % 6
	qu.push(x)
	d = qu.prod
	print(d)