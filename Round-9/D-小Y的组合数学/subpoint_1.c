#include <stdio.h>

const int P = 998244353;

int dfs(int x, int k) {
    if (x < 0) return 0;
    if (k == 0) return x == 0;
    return (dfs(x + 1, k - 1) + dfs(x - 1, k - 1)) % P;
}

int main() {
    int x, k;
    scanf("%d %d", &x, &k);
    printf("%d\n", dfs(x, k));
    return 0;
}