k = float(input())

def f(x):
	print("? %.10f" % x)
	y = float(input())
	return y - k

ans = 0
v = 10000
for i in range(1, 100):
    a = abs(f(i))
    if a < v:
        ans = i
        v = a

print("! %.10f" % ans)