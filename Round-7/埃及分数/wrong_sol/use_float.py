n = int(input())
v = list(map(int, input().split()))
val = 0
for i in range(n):
	val += 1 / v[i]
ans = []
p = 2
eps = 1e-9
while val > eps:
	if val - 1 / p > -eps:
		if p != v[len(v) - 1]:
			val -= 1 / p
			ans.append(p)
	p += 1
print(len(ans))
print(*ans)