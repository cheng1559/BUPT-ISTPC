x = set(map(int, input().split()))
y = set(map(int, input().split()))
x_is_subset_of_y = x.issubset(y)
y_is_subset_of_x = y.issubset(x)
if x_is_subset_of_y and y_is_subset_of_x:
	print('=')
elif x_is_subset_of_y:
	print('<')
elif y_is_subset_of_x:
	print('>')
else:
	print('.')