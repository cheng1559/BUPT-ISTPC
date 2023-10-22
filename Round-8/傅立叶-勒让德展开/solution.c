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

double asr(double l, double r, double eps, double value) {
    double mid = (l + r) / 2;
    double l_value = simpson(l, mid);
    double r_value = simpson(mid, r);
    if (fabs(l_value + r_value - value) <= eps)
        return l_value + r_value;
    return asr(l, mid, eps / 2, l_value) + asr(mid, r, eps / 2, r_value);
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
    printf("%lf\n", asr(-1, 1, 1E-6, simpson(-1, 1)) * (2 * n + 1) / 2);
}