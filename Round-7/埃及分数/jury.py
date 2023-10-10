input()
v = list(map(int, input().split()))
print(len(v) + 1)
print(*v[:-1], v[-1] + 1, v[-1] * (v[-1] + 1))