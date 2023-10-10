#include <iostream>
int main() {
	int k, n;
	std::cin >> k;
	std::cout << k + 1 << std::endl;
	while (--k) {
		std::cin >> n;
		std::cout << n << " ";
	}
	std::cin >> n;
	std::cout << (n + 1) << " " << (n + 1) * n << std::endl;
	return 0;
}