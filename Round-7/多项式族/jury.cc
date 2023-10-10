#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

static double interpolate(int val, const std::vector<std::pair<int, int>> &known) {
	for (auto &[x, y] : known) {
		if (val == x) {
			return y; // In this case we don't need to interpolate.
		}
	}
	double ret = 0;
	for (int i = 0; i < (int)known.size(); i++) {
		double prod = known[i].second;	
		for (int j = 0; j < (int)known.size(); j++) {
			if (i != j) {
				prod = prod * (val - known[j].first) / (known[i].first - known[j].first);
			}
		}
		ret = ret + prod;
	}
	return ret;
}

static bool dbl_eq(double x, double y) {
	return std::abs(x - y) / std::max(std::max(std::abs(x), std::abs(y)), 1.0) <= 1e-6;
}

int main(void) {
	int order;
	std::cin >> order;
	std::vector<std::pair<int, int>> f(order + 1), g(order + 1);
	for (auto &[x, y] : f) {
		std::cin >> x >> y;
	}
	for (auto &[x, y] : g) {
		std::cin >> x >> y;
	}
	double c = f[0].second - interpolate(f[0].first, g);
	for (auto &[x, y] : f) {
		if (!dbl_eq(interpolate(x, g) + c, y)) {
			std::cout << "NO" << std::endl;
			return 0;
		}
	}
	std::cout << "YES" << std::endl;
	std::cout << std::fixed << std::setprecision(10) << c << std::endl;
	return 0;
}