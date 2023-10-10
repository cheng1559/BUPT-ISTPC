#include <stdio.h>
#include <math.h>
#include <stdbool.h>

struct Point {
	int x, y;
};

static double interpolate(int x, int n, struct Point points[]) {
	for (int i = 0; i < n; i++) {
		if (points[i].x == x) {
			return points[i].y;
		}
	}
	double y = 0;
	for (int i = 0; i < n; i++) {
		double t = points[i].y;
		for (int j = 0; j < n; j++) {
			if (i != j) {
				t *= ((double)x - points[j].x) / (points[i].x - points[j].x);
			}
		}
		y += t;
	}
	return y;
}

static bool dbl_eq(double x, double y) {
	return fabs(x - y) / fmax(fmax(fabs(x), fabs(y)), 1.0) <= 1e-6;
}

int main(void) {
	int n;
	scanf("%d", &n);
	struct Point f[n + 1], g[n + 1];
	for (int i = 0; i <= n; i++) {
		scanf("%d%d", &f[i].x, &f[i].y);
	}
	for (int i = 0; i <= n; i++) {
		scanf("%d%d", &g[i].x, &g[i].y);
	}
	double c = f[0].y - interpolate(f[0].x, n + 1, g);
	for (int i = 1; i <= n; i++) {
		if (!dbl_eq(f[i].y, interpolate(f[i].x, n + 1, g) + c)) {
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	printf("%.10f\n", c);
	return 0;
}