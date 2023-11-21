#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int poly[n + 1];
    for (int i = 0; i <= n; ++i) {
        scanf("%d", &poly[i]);
    }
    for (int i = 0; i <= n - 1; ++i) {
        poly[i] = poly[i + 1] * (i + 1);
    }
    for (int i = 0; i <= n - 2; ++i) {
        poly[i] = poly[i + 1] * (i + 1);
        printf("%d ", poly[i]);
    }
    return 0;
}