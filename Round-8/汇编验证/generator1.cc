#include "testlib.h"
#include <string>

int main(int argc, char *argv[]) {
	registerGen(argc, argv, 1);
	int n = std::stoi(argv[1]);
	if (n == 1) {
		std::cout << 1;
		std::cout << '\n' << 1 << ' ' << 1 << ' ' << 1;
		std::cout << '\n' << 10000 << " " << 0 << " " << 1 << " " << 1;
		for (int i = 0; i < 10000; i++) {
			std::cout << '\n' << 1;
		}
	} else if (n == 2) {
		std::cout << 2;
		std::cout << '\n' << 1 << ' ' << 1 << ' ' << 1;
		std::cout << '\n' << 0 << ' ' << 1 << ' ' << 1;
		std::cout << '\n' << 10000 << " " << 0 << " " << 1 << " " << 1;
		for (int i = 0; i < 9999; i++) {
			std::cout << '\n' << 1;
		}
		std::cout << '\n' << 2;
	} else if (n == 3) {
		std::cout << 2;
		std::cout << '\n' << 1 << ' ' << 1 << ' ' << 1;
		std::cout << '\n' << 2 << ' ' << 0;
		std::cout << '\n' << 10000 << " " << 2 << " " << 1 << " " << 1;
		for (int i = 0; i < 9999; i++) {
			std::cout << '\n' << 1;
		}
		std::cout << '\n' << 2;
	} else if (n == 4) {
		std::cout << 2;
		std::cout << '\n' << 1 << ' ' << 1 << ' ' << 1;
		std::cout << '\n' << 2 << ' ' << 0;
		std::cout << '\n' << 10000 << " " << 2 << " " << 1 << " " << 1;
		for (int i = 0; i < 10000; i++) {
			std::cout << '\n' << 2;
		}
	} else if (n == 5) {
		std::cout << 3;
		std::cout << '\n' << 1 << ' ' << 1 << ' ' << 1;
		std::cout << '\n' << 0 << ' ' << 1 << ' ' << 1;
		std::cout << '\n' << 2 << ' ' << 0;
		std::cout << '\n' << 10000 << " " << 2 << " " << 1 << " " << 1;
		for (int i = 0; i < 9999; i++) {
			std::cout << '\n' << 1;
		}
		std::cout << '\n' << 3;
	}
	return 0;
}