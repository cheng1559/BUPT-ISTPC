n, m = map(int, input().split(' '))

degree = [0 for _ in range(n + 1)]

for _ in range(m):
    u, v = map(int, input().split(' '))
    degree[u] += 1
    degree[v] += 1
    
end = False
for i in range(2, n + 1):
    if degree[i] % 2 == 1:
        if not end:
            end = True
        else:
            print('NO')
            exit(0)
if end == True:
    print('YES')
else:
    print('NO')