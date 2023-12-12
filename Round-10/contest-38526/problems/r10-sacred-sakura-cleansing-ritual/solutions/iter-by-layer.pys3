n, m = map(int, input().split(' '))
edges = [[] for _ in range(n + 1)]
number = [0 for _ in range(n + 1)]
for _ in range(m):
	u, v = map(int, input().split(' '))
	edges[u].append(v)
	edges[v].append(u)
 
number[1] = 1
p = 1; d = 1
while p:
	e = edges[p]; p = None
	for v in e:
		if number[v] == 0:
			number[v] = d + 1
			p = v
	d += 1
stat = [0 for _ in range(n + 2)]
for i in range(1, n + 1):
	stat[number[i]] += 1
for i in range(1, n + 1):
	if number[i] == 0 or stat[number[i] - 1] + stat[number[i] + 1] != len(edges[i]) or \
			not all(abs(number[i] - number[j]) == 1 for j in edges[i]):
		print('NO')
		exit()
print('YES')
print(*number[2:])