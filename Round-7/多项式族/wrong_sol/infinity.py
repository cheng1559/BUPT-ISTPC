def lagrange(known_points, x):
	for xi, yi in known_points:
		if xi == x:
			return yi
	sum = 0
	for i in range(len(known_points)):
		product = known_points[i][1]
		for j in range(len(known_points)):
			if i != j:
				product *= (x - known_points[j][0]) / (known_points[i][0] - known_points[j][0])
		sum += product
	return sum

def read_poly(n):
	points = []
	for _ in range(n + 1):
		x, y = map(int, input().split())
		points.append((x, y))
	return points

def dbl_eq(a, b):
	return abs(a - b) / max(abs(a), abs(b), 1) < 1e-6

n = int(input())
f = read_poly(n)
g = read_poly(n)

c = f[0][1] - lagrange(g, f[0][0])
for i in range(1, n + 1):
	if not dbl_eq(lagrange(g, f[i][0]) + c, f[i][1]):
		print('NO')
		exit()
print('YES')
print("1e500")