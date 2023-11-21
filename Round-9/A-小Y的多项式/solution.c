#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int poly[n + 1];
    for (int i = 0; i <= n; ++i) {
        scanf("%d", &poly[i]);
    }
    for (int i = 0; i <= n - 2; ++i) {
        printf("%lld ", 1LL * (i + 1) * (i + 2) * poly[i + 2]);
    }
    return 0;
}