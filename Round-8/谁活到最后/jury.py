def josephus(x, n):
	if n == 1:
		return x
	currx, curry = 1, 0
	nextx, nexty = 0, 0
	while True:
		step = (currx - curry + n - 2) // (n - 1)
		nextx = currx + step
		nexty = (curry + n * step) % nextx
		if x < nextx:
			return curry + n * (x - currx) + 1
		currx, curry = nextx, nexty

print(josephus(*map(int, input().split(" "))))