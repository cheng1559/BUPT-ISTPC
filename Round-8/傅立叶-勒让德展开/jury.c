#include <stdio.h>
#include <math.h>

double P[55][55];
int n, a, b;

double f(double x) {
    double ans = 0, tx = 1;
    for (int i = 0; i <= n; ++i) {
        ans += P[n][i] * tx;
        tx *= x;
    }
    ans *= cos(a * x + b);
    return ans;
}

double simpson(double l, double r) {
    double mid = l + (r - l) / 2;
    return (r - l) * (f(l) + 4 * f(mid) + f(r)) / 6;
}

double integral(double l, double r, int n) {
    double res = 0, h = (r - l) / n;
    for (int k = 0; k < n; ++k) {
        res += simpson(l + k * h, l + (k + 1) * h);
    }
    return res;
}

int main() {
    scanf("%d %d %d", &a, &b, &n);
    P[0][0] = 1;
    P[1][1] = 1;
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (j) P[i][j] = P[i - 1][j - 1] * (2 * i - 1) / i;
            P[i][j] -= P[i - 2][j] * (i - 1) / i;
        }
    }
    printf("%lf\n", integral(-1, 1, 5000) * (2 * n + 1) / 2);
    return 0;
}