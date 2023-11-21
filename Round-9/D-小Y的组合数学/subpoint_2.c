#include <stdio.h>

#define MAXN 2000005
const int P = 998244353;

int dp[2][MAXN];

int main() {
    int x, k;
    scanf("%d %d", &x, &k);
    dp[0][0] = 1;
    int t = 1;
    for (int i = 1; i <= k; ++i, t ^= 1) {
        dp[t][0] = dp[t ^ 1][1];
        for (int j = 1; j <= x + k; ++j) {
            dp[t][j] = (dp[t ^ 1][j - 1] + dp[t ^ 1][j + 1]) % P;
        }
    }
    printf("%d\n", dp[t ^ 1][x]);
    return 0;
}