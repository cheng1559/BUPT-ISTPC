MOD = 998244353

def matrix_mul(A, B):
	n = len(A)
	C = [[0] * n for _ in range(n)]
	for i in range(n):
		for j in range(n):
			for k in range(n):
				C[i][j] += A[i][k] * B[k][j]
				C[i][j] %= MOD
	return C

def matrix_pow(A, k):
	n = len(A)
	res = [[0] * n for _ in range(n)]
	for i in range(n):
		res[i][i] = 1
	while k > 0:
		if k % 2 == 1:
			res = matrix_mul(res, A)
		A = matrix_mul(A, A)
		k //= 2
	return res

k = int(input())
t = matrix_pow([
	[2, 1],
	[1, 0]
], k - 1)
print((2 * t[0][0] + t[0][1]) % MOD)