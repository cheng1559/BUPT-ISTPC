#include <stdio.h>

#define MAXN 10005
int stack[MAXN];
int top;
int rett[MAXN], argc[MAXN], argt[MAXN][50];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d %d", &rett[i], &argc[i]);
        for (int j = 0; j < argc[i]; ++j) {
            scanf("%d", &argt[i][j]);
        }
    }
    int s, r, c;
    scanf("%d %d %d", &s, &r, &c);
    for (int i = 0; i < c; ++i) {
        int t;
        scanf("%d", &t);
        stack[top++] = t;
    }
    for (int t = 0; t < s; ++t) {
        int i;
        scanf("%d", &i);
        for (int j = argc[i] - 1; j >= 0; --j) {
            if (top == 0 || argt[i][j] != stack[top - 1]) {
                printf("NO\n");
                return 0;
            }
            --top;
        }
        if (rett[i]) stack[top++] = rett[i];
    }
    if ((r == 0 && top == 0) || (r && top == 1 && stack[top - 1] == r)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
}