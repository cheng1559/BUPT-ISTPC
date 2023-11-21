#include <stdio.h>

#define MAXN 1000005
char s[MAXN];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    while (m--) {
        scanf("%s", s);
        int flag = 0;
        for (int i = 0, ones = 0; s[i] != '\0'; ++i) {
            if (s[i] == '1') ++ones;
            else ones = 0;
            if (ones >= n) {
                flag = 1;
                break;
            }
        }
        if (flag) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}