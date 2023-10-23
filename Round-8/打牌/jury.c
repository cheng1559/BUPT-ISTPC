#include <stdio.h>

int queue[100004], l, r;
int cnt[6];

void print(__int128_t x) {
    if (x >= 10) print(x / 10);
    putchar(x % 10 + '0');
}

int main() {
    int n, q;
    __int128_t prev_d = 0;
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
        __int128_t d = 1;
        for (int i = 0; i < 6; ++i) {
            d *= cnt[i] + 1;
        }
        print(d); putchar('\n');
        prev_d = d;
    }
}