#include "testlib.h"
#include <cassert>
#include <map>

enum GenType {
	EQUALS,
	X_CONTAINS_Y,
	Y_CONTAINS_X,
	NONE
};

static std::map<std::string, GenType> gen_type_map = {
	{"equals", EQUALS},
	{"x_contains_y", X_CONTAINS_Y},
	{"y_contains_x", Y_CONTAINS_X},
	{"none", NONE}
};

#define INPUT_MAX_VAL 1000000000

int main(int argc, char *argv[]) {
	registerGen(argc, argv, 1);
	if (argc < 4 || gen_type_map.find(argv[1]) == gen_type_map.end()) {
		std::cerr << "Usage: " << argv[0] << " <equals|x_contains_y|y_contains_x|none> <x_len> <y_len> [seed]" << std::endl;
		return 1;
	}
	GenType gen_type = gen_type_map[argv[1]];
	int x_len = std::stoi(argv[2]), y_len = std::stoi(argv[3]);
	int common_len;
	if (gen_type == EQUALS) {
		assert(x_len == y_len);
		common_len = x_len;
	} else if (gen_type == X_CONTAINS_Y) {
		assert(x_len > y_len);
		common_len = y_len;
	} else if (gen_type == Y_CONTAINS_X) {
		assert(y_len > x_len);
		common_len = x_len;
	} else {
		common_len = rnd.next(0, std::min(x_len, y_len));
	}
	int x_extra = x_len - common_len, y_extra = y_len - common_len;
	std::set<int> common, x, y;
	while (common_len > 0) {
		int next = rnd.next(0, INPUT_MAX_VAL);
		if (common.find(next) == common.end()) {
			common.insert(next);
			common_len--;
		}
	}
	while (x_extra > 0) {
		int next = rnd.next(0, INPUT_MAX_VAL);
		if (x.find(next) == x.end() && common.find(next) == common.end()) {
			x.insert(next);
			x_extra--;
		}
	}
	while (y_extra > 0) {
		int next = rnd.next(0, INPUT_MAX_VAL);
		if (y.find(next) == y.end() && x.find(next) == x.end() && common.find(next) == common.end()) {
			y.insert(next);
			y_extra--;
		}
	}
	x.insert(common.begin(), common.end());
	y.insert(common.begin(), common.end());
	std::cout << x.size();
	for (int e : x) {
		std::cout << " " << e;
	}
	std::cout << std::endl;
	std::cout << y.size();
	for (int e : y) {
		std::cout << " " << e;
	}
	std::cout << std::endl;
}