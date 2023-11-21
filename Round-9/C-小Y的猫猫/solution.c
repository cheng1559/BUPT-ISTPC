#include <stdio.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int father[n + 1];
    int ans[n + 1], idx;
    for (int i = 1; i <= n; ++i) {
        father[i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        int l, r;
        scanf("%d %d", &l, &r);
        if (l) father[l] = i;
        if (r) father[r] = i;
    }
    while (k) {
        ans[idx++] = k;
        k = father[k];
    }
    for (int i = idx - 1; i > -idx; --i) {
        printf("%d ", ans[abs(i)]);
    }
    return 0;
}