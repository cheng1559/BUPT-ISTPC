#include <iostream>
#include <vector>

int main() {
	int n;
	std::cin >> n;
	std::vector<int> x(n);
	for (auto &v : x) {
		std::cin >> v;
	}
	std::cin >> n;
	std::vector<int> y(n);
	for (auto &v : y) {
		std::cin >> v;
	}
	auto x_it = x.begin(), y_it = y.begin();
	bool x_ge = true, y_ge = true;
	while (x_it != x.end() || y_it != y.end()) {
		if (x_it == x.end()) {
			x_ge = false;
			break;
		} else if (y_it == y.end()) {
			y_ge = false;
			break;
		} else if (*x_it < *y_it) {
			y_ge = false, x_it++;
		} else if (*x_it > *y_it) {
			x_ge = false, y_it++;
		} else {
			x_it++, y_it++;
		}
	}
	if (x_ge && y_ge) {
		std::cout << "=" << std::endl;
	} else if (x_ge) {
		std::cout << ">" << std::endl;
	} else if (y_ge) {
		std::cout << "<" << std::endl;
	} else {
		std::cout << "." << std::endl;
	}
}