n, m = map(int, input().split(' '))

degree = [0 for _ in range(n + 1)]

for _ in range(m):
    u, v = map(int, input().split(' '))
    degree[u] += 1
    degree[v] += 1

print('YES' if sum(i % 2 for i in degree[2:]) <= 1 else 'NO')