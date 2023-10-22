#include <stdio.h>

long long solve(long long x, int n) {
    if (n == 1) return x;
    int s = 0;
    long long i = 1;
    while (1) {
        long long k = (i - s + n - 2) / (n - 1);
        if (x < i + k) return s + n * (x - i) + 1;
        i += k;
        s = (s + n * k) % i;
    }
    return 0;
}

int main() {
    long long x;
    int n;
    scanf("%lld %d", &x, &n);
    printf("%lld\n", solve(x, n));
}