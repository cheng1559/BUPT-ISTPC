#include "testlib.h"

int main(int argc, char * argv[]) {
	registerGen(argc, argv, 1);
	if (argc < 5) {
		printf("Usage: %s <t> <minx> <maxx> <maxn>\n", argv[0]);
		return 1;
	}
	int t = std::stoi(argv[1]);
	long long minx = std::stoll(argv[2]);
	long long maxx = std::stoll(argv[3]);
	int maxn = std::stoi(argv[4]);
	if (minx == maxx) {
		for (int i = 1; i <= maxn; i++) {
			std::cout << minx << " " << i << std::endl;
		}
		return 0;
	}
	for (int i = 0; i < t; i++) {
		long long x = rnd.next(minx, maxx);
		int n = rnd.next(1, maxn);
		std::cout << x << " " << n << std::endl;
	}
	return 0;
}