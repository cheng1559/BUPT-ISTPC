n = int(input())
v = [0 for _ in range(21)]
s = input().split(" ")
for i in range(n):
    v[i] = int(s[i])
last = v[n - 1]
v[n - 1] = last + 1
v[n] = last * (last + 1)
print(n + 1)
print(*v[: n + 1])
