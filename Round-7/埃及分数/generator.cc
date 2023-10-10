#include "common.hh"
#include <algorithm>
#include <iterator>
#include <string>
#include <unordered_set>

int main(int argc, char *argv[]) {
	registerGen(argc, argv, 1);
	if (argc < 3) {
		std::cerr << "Usage: " << argv[0] << " <rand|con1|pow2|pow3> <n> [random]" << std::endl;
		return 1;
	}
	int n = std::stoi(argv[2]);
	std::vector<int> vec;
	if (strcmp(argv[1], "rand") == 0) {
		std::unordered_set<int> s;
		cave::BigUnsigned numerator, denominator{1};
		int global_max_attempt = 500;
		while (global_max_attempt-- && (int)vec.size() != n) {
			s.clear();
			vec.clear();
			for (int i = 0, max_attempt = 500; i < n && max_attempt; max_attempt--) {
				uint32_t nval = rnd.next(2, INPUT_MAX_VAL);
				if (s.find(nval) == s.end()) {
					auto nnumerator = numerator, ndenominator = denominator;
					cave::b_mul(nnumerator, {nval});
					cave::b_add(nnumerator, ndenominator);
					cave::b_mul(ndenominator, {nval});
					if (cave::b_cmp(nnumerator, ndenominator) < 0) {
						vec.push_back(nval);
						s.insert(nval);
						numerator = nnumerator;
						denominator = ndenominator;
						i++;
					}
				}
			}
		}
		std::sort(vec.begin(), vec.end());
	} else if (strcmp(argv[1], "conm") == 0) {
		for (int i = 0; i < n; i++) {
			vec.push_back(INPUT_MAX_VAL - i);
		}
		std::reverse(vec.begin(), vec.end());
	} else if (strcmp(argv[1], "pow2") == 0) {
		for (int i = 0; i < n; i++) {
			vec.push_back(1 << (i + 1));
		}
	} else if (strcmp(argv[1], "pow3") == 0) {
		int x = 2;
		for (int i = 0; i < n; i++) {
			vec.push_back(x);
			x *= 3;
		}
	} else {
		std::cerr << "Usage: " << argv[0] << " <rand|cont|pow2|pow3> [random]" << std::endl;
		return 1;
	}
	std::cout << n << std::endl;
	for (int i = 0; i < n; i++) {
		std::cout << vec[i] << (i == n - 1 ? "" : " ");
	}
	return 0;
}