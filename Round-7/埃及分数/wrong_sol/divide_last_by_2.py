input()
v = list(map(int, input().split()))
last = v[len(v) - 1]
v[len(v) - 1] = last * 2
v.append(last * 2)
print(len(v))
print(*v)