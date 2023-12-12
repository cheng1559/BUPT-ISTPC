import collections

n, m = map(int, input().split(' '))
edges = [[] for _ in range(n + 1)]
number = [None for _ in range(n + 1)]
for _ in range(m):
	u, v = map(int, input().split(' '))
	edges[u].append(v)
	edges[v].append(u)

stat = [0 for _ in range(n + 2)]
number[1] = 1
stat[1] = 1
qu = collections.deque([1])
while qu:
	u = qu.popleft()
	for v in edges[u]:
		if number[v] is None:
			number[v] = number[u] + 1
			stat[number[v]] += 1
			qu.append(v)
		elif abs(number[v] - number[u]) != 1: # should not connect to a node in layer not adjacent to current layer
			print('NO')
			exit()
for i in range(2, n):
	if stat[number[i] + 1] + stat[number[i] - 1] != len(edges[i]): # should fully connected to its previous and next layer
		print('NO')
		exit()
print('YES')
print(*number[2:])