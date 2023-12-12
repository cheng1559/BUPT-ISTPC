k = float(input())

def f(x):
	print("? %.10f" % x)
	y = float(input())
	return y - k

def secant(g1, g2, backwardeps):
	lbound = g1
	rbound = g2
	be1 = f(g1)
	be2 = f(g2)
	while abs(be2) >= backwardeps:
		l = 1
		g3 = g2 - be2 * (g2 - g1) / (be2 - be1)
		while g3 < lbound or g3 > rbound:
			l /= 2
			g3 = g2 - l * be2 * (g2 - g1) / (be2 - be1)
		g1, g2 = g2, g3
		be1 = be2
		be2 = f(g2)
		if be2 > 0:
			rbound = g2
		else:
			lbound = g2
	return g2

ans = secant(0, 100, 1e-6)

print("! %.10f" % ans)