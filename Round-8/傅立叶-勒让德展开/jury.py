from math import sin, cos

def legendre(n):
	ppp, pp, p = [1], [0, 1], None
	if n == 0:
		return ppp
	elif n == 1:
		return pp
	for i in range(2, n + 1):
		p = [0] * (len(pp) + 1)
		for j in range(len(pp)):
			p[j + 1] += (2 * i - 1) / i * pp[j]
		for j  in range(len(ppp)):
			p[j] -= (i - 1) / i * ppp[j]
		ppp, pp = pp, p
	return p

def fit(a, b, order):
	if a == 0:
		return cos(b) if order == 1 else 0
	p = legendre(order)
	r1, r2 = 0, 0
	ans = 0
	for i in range(len(p) - 1, -1, -1):
		f = r1 + p[i]
		n = (-1) ** i
		ans += f * (\
			1 / a * (sin(a + b) + n * sin(a - b)) + \
			i / a ** 2 * (cos(a + b) + n * cos(a - b))\
		)
		r1, r2 = r2, -f * i * (i - 1) / a ** 2
	return ans * (2 * order + 1) / 2

print(fit(*map(int, input().split(" "))))