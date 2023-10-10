x = list(map(int, input().split()))
y = list(map(int, input().split()))
if x == y:
	print("=")
elif x[0] > y[0]:
	print(">")
elif x[0] < y[0]:
	print("<")
else:
	print(".")