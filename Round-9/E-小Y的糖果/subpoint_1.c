#include <stdio.h>
#include <stdlib.h>

const int P = 998244353;

int dfs(int cur, int remain, int m, int k) {
    if (cur == m) return remain == 0;
    int ans = 0;
    for (int i = 0; i <= k && i <= remain; ++i) {
        ans += dfs(cur + 1, remain - i, m, k);
    }
    return ans;
}

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    int ans = dfs(0, n, m, k);
    printf("%d\n", ans);
    return 0;
}