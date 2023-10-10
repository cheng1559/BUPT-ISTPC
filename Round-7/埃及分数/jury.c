#include <stdio.h>

int main(void) {
	int k, n;
	scanf("%d", &k);
	printf("%d\n", k + 1);
	while (--k) {
		scanf("%d", &n);
		printf("%d ", n);
	}
	scanf("%d", &n);
	printf("%d %d\n", n + 1, n * (n + 1));
	return 0;
}