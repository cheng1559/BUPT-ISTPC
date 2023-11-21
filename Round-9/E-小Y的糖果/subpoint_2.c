#include <stdio.h>
#include <stdlib.h>
#define MAXN 5005
const int P = 998244353;

int dp[MAXN][MAXN];

int dfs(int cur, int remain, int m, int k) {
    if (cur == m) return remain == 0;
    if (dp[cur][remain]) return dp[cur][remain];
    int ans = 0;
    for (int i = 0; i <= k && i <= remain; ++i) {
        ans = (ans + dfs(cur + 1, remain - i, m, k)) % P;
    }
    return dp[cur][remain] = ans;
}

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    int ans = dfs(0, n, m, k);
    printf("%d\n", ans);
    return 0;
}