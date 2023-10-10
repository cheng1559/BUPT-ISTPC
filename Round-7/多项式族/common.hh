#ifdef GENERATOR
#include <cassert>
#include <cstdint>
#include <ctime>
#include <string>
#include <algorithm>
#include <vector>
#include <gmpxx.h>

namespace cave {
using Q = mpq_class;

[[maybe_unused]]
static Q interpolate(int val, const std::vector<std::pair<int, int>> &known) {
	for (auto &[x, y] : known) {
		if (val == x) {
			return y; // In this case we don't need to interpolate.
		}
	}
	Q ret;
	for (int i = 0; i < (int)known.size(); i++) {
		Q prod = known[i].second;	
		for (int j = 0; j < (int)known.size(); j++) {
			if (i != j) {
				prod = prod * (val - known[j].first) / (known[i].first - known[j].first);
			}
		}
		ret = ret + prod;
	}
	return ret;
}
} // namespace cave
#endif

// Information about this problem.
// High-order interpolation causes unacceptable precision loss, so we limit the order to 8.
#define MAX_ORDER 8
#define MAX_ABS_X 100
#define MAX_ABS_Y 1000000000