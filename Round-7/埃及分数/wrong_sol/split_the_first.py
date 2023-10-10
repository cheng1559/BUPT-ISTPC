input()
v = list(map(int, input().split()))
first = v[0]
print(len(v) + 1)
v1 = v[1:]
v1.append(first + 1)
v1.append(first * (first + 1))
print(*sorted(v1))