k = float(input())

def f(x):
	print("? %.10f" % x)
	y = float(input())
	return y - k

def biselect(l, r, eps):
	while r - l >= eps:
		m = (r + l) / 2
		if f(m) >= 0:
			r = m
		else:
			l = m
	return (r + l) / 2

ans = biselect(0, 100, 1e-6)

print("! %.10f" % ans)