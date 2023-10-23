class Func:
	def __init__(self, rval, args):
		self.rval = rval
		self.args = list(reversed(args)) # Turn the push-order into pop-order

class Stack:
	def __init__(self, init):
		self.items = init
	
	def call(self, func):
		for j in func.args:
			if len(self.items) == 0 or self.items.pop() != j:
				return False
		if func.rval != 0:
			self.items.append(func.rval)
		return True

n = int(input())
funcs = [None]
for i in range(n):
	rval, _, *args = map(int, input().split())
	funcs.append(Func(rval, args))
s, r, _, *p = map(int, input().split())
stack = Stack(p)
line = 0
for i in range(s):
	j = int(input())
	line += 1
	if not stack.call(funcs[j]):
		print("NO")
		exit(0)
if (r == 0 and len(stack.items) == 0) or (stack.items[-1] == r):
	print("YES")
else:
	print("NO")