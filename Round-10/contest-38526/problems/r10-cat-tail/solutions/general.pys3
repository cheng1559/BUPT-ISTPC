MOD = 998244353 * 2 # Multiply by 2 so that we can always divide by 2 at the end

def ir_mul(a, b): # Multiply two irrationals in form a + b sqrt(2)
	return ((a[0] * b[0] + 2 * a[1] * b[1]) % MOD, (a[0] * b[1] + a[1] * b[0]) % MOD)

def ir_pow(a, n):
	ret = (1, 0)
	while n:
		if n & 1:
			ret = ir_mul(ret, a)
		a = ir_mul(a, a)
		n >>= 1
	return ret

print(ir_mul(ir_pow((1, 1), int(input())), (2, 1))[0] // 2)