n, m = map(int, input().split(' '))

degree = [0 for _ in range(n + 1)]

for _ in range(m):
    u, v = map(int, input().split(' '))
    degree[u] += 1
    degree[v] += 1
    
cnt = 0
for i in range(1, n + 1):
    cnt += degree[i] % 2
print('YES' if cnt <= 2 else 'NO')