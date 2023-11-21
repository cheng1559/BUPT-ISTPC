#include <stdio.h>
#define MAXN 1000005
const int P = 998244353;

int fac[MAXN];

int inv(int x) {
    if (x == 1) return 1;
    return 1LL * (P - P / x) * inv(P % x) % P;
}

int divide(int a, int b) {
    return 1LL * a * inv(b) % P;
}

int comb(int n, int m) {
    if (n < m || m < 0) return 0;
    return divide(divide(fac[n], fac[m]), fac[n - m]);
}

int main() {
    int x, k;
    scanf("%d %d", &x, &k);
    if ((k - x) % 2) {
        printf("0\n");
        return 0;
    }
    fac[0] = 1;
    for (int i = 1; i <= k; ++i) {
        fac[i] = 1LL * fac[i - 1] * i % P;
    }
    int ans = (comb(k, (k - x) / 2) - comb(k, (k - x - 2) / 2) + P) % P;
    printf("%d\n", ans);
    return 0;
}