#include <stdio.h>
#include <stdbool.h>

int main() {
	int n, m;
	scanf("%d", &n);
	int x[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &x[i]);
	}
	scanf("%d", &m);
	int y[m];
	for (int i = 0; i < m; i++) {
		scanf("%d", &y[i]);
	}
	int x_it = 0, y_it = 0;
	bool x_ge = true, y_ge = true;
	while (x_it != n || y_it != m) {
		if (x_it == n) {
			x_ge = false;
			break;
		} else if (y_it == m) {
			y_ge = false;
			break;
		} else if (x[x_it] < y[y_it]) {
			y_ge = false, x_it++;
		} else if (x[x_it] > y[y_it]) {
			x_ge = false, y_it++;
		} else {
			x_it++, y_it++;
		}
	}
	if (x_ge && y_ge) {
		printf("=\n");
	} else if (x_ge) {
		printf(">\n");
	} else if (y_ge) {
		printf("<\n");
	} else {
		printf(".\n");
	}
}