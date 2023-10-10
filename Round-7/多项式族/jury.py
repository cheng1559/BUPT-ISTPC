def lagrange(known, x):
	sum = 0
	for i in range(len(known)):
		product = known[i][1]
		for j in range(len(known)):
			if i != j:
				product *= (x - known[j][0]) / (known[i][0] - known[j][0])
		sum += product
	return sum

n = int(input())
f = [list(map(int, input().split())) for _ in range(n + 1)]
g = [list(map(int, input().split())) for _ in range(n + 1)]

c = f[0][1] - lagrange(g, f[0][0])
for i in range(1, n + 1):
	if abs(lagrange(g, f[i][0]) + c - f[i][1]) > 1e-6:
		print('NO')
		exit()
print('YES')
print(c)