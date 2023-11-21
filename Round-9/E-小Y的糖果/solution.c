#include <stdio.h>
#define MAXN 2000005

const int P = 998244353;

int fac[MAXN], inv[MAXN], fac_inv[MAXN];

void init_inv(int n) {
    inv[1] = 1;
    for (int i = 2; i <= n; i++) {
        inv[i] = 1LL * (P - P / i) * inv[P % i] % P;
    }
}

int comb(long long n, int m) {
    if (n < m || m < 0) return 0;
    return 1LL * fac[n] * fac_inv[m] % P * fac_inv[n - m] % P;
}

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    init_inv(n + m - 1);
    fac_inv[0] = fac[0] = 1;
    for (int i = 1; i <= n + m - 1; ++i) {
        fac[i] = 1LL * fac[i - 1] * i % P;
        fac_inv[i] = 1LL * fac_inv[i - 1] * inv[i] % P;
    }
    long long ans = 0;
    for (int i = 0; i <= m; ++i) {
        ans += (i % 2 ? -1LL : 1LL) * comb(m, i) * comb(n - 1LL * i * (k + 1) + m - 1, m - 1) % P;
        ans = (ans + P) % P;
    }
    printf("%lld\n", ans);
    return 0;
}