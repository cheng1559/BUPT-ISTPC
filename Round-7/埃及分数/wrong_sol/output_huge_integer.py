input()
v = list(map(int, input().split()))
last = v[len(v) - 1]
v[len(v) - 1] = last + 1
v.append(last * (last + 1) + 1)
v.append((last * (last + 1) + 1) * last * (last + 1))
print(len(v))
print(*v)