#include <stdio.h>
#include <string.h>

#define MAXN 100005
char s[MAXN];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    while (m--) {
        scanf("%s", s);
        int len = strlen(s);
        int flag = 0;
        for (int i = 0; i < len; ++i) {
            int ones = 0;
            for (int j = i; j < len; ++j) {
                ones += s[j] == '1';
            }
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