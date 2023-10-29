#include <stdio.h>

int queue[100004], l, r;
int cnt[6];

int main() {
    int n, q;
    long long prev_d = 0;
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        x = (x + prev_d) % 6;
        queue[r++] = x;
        ++cnt[x];
        if (i >= q) {
            --cnt[queue[l++]];
        }
        long long d = 1;
        for (int i = 0; i < 6; ++i) {
            d *= cnt[i] + 1;
        }
        printf("%lld\n", d);
        prev_d = d;
    }
}