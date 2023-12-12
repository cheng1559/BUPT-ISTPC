MOD = 998244353
SQRT2 = 116195171
INV4 = 748683265

def mod_pow(x, n):
    ret = 1
    while n > 0:
        if n & 1:
            ret = ret * x % MOD
        x = x * x % MOD
        n >>= 1
    return ret

k = int(input())
print(((2 + SQRT2) * mod_pow(1 + SQRT2, k) + (2 - SQRT2) * mod_pow(1 - SQRT2, k)) * INV4 % MOD)