#include "testlib.h"
#include <string>
#include <iostream>

int main(int argc, char *argv[]) {
	registerGen(argc, argv, 1);
	if (argc < 3) {
		fprintf(stderr, "Usage: %s <n> <q>\n", argv[0]);
		return 1;
	}
	int n = std::stoi(argv[1]), q = std::stoi(argv[2]);
	std::cout << n << " " << q;
	for (int i = 0; i < n; i++) {
		std::cout << "\n" << rnd.next(0, 6);
	}
	return 0;
}