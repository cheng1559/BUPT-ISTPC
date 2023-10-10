#include <cmath>
#include <cstring>
#include <math.h>
#define GENERATOR
#include "common.hh"
#include "testlib.h"
#include <algorithm>
#include <set>
#include <utility>
#include <vector>

using cave::Q;

static bool debug_message = false;

static std::vector<std::pair<int, int>> integer_points(const std::vector<Q> &poly) {
	std::vector<std::pair<int, int>> ret;
	for (int i = -MAX_ABS_X; i <= MAX_ABS_X; i++) {
		Q y = 0;
		Q x = i;
		Q prod = 1;
		for (int j = 0; j < (int)poly.size(); j++) {
			y = y + prod * poly[j];
			prod = prod * x;
		}
		if (debug_message) {
			std::cerr << "    [Generator] P(" << i << ") = " << y << std::endl;
		}
		if (y.get_den() == 1 && abs(y.get_num().get_si()) <= MAX_ABS_Y) {
			ret.emplace_back(i, y.get_num().get_si());
		}
	}
	return ret;
}

static void shuffle(std::vector<std::pair<int, int>> &arr) {
	for (int i = 0; i < (int)arr.size(); i++) {
		int j = rnd.next(i, (int)arr.size() - 1);
		std::swap(arr[i], arr[j]);
	}
}

int main(int argc, char *argv[]) {
	registerGen(argc, argv, 1);
	bool ans;
	if (argc <= 1) {
		ans = rnd.next(0, 1);
	} else {
		ans = !strcmp("yes", argv[1]);
	}
	int maxn = argc - 3;
	std::vector<Q> poly;
	for (int i = 2; i < argc; i++) {
		poly.emplace_back(argv[i]);
	}
	std::vector<std::pair<int, int>> f, g;
	bool okay = false;
	Q c;
	f = integer_points(poly);
	ensure((int)f.size() >= maxn + 1);
	if ((int)f.size() < 2 * maxn + 1) {
		std::cerr << "    [Generator] Warning: f has only " << f.size() << " points." << std::endl;
	}
	while (!okay) {
		auto poly1 = poly;
		int lim = (int)(pow(MAX_ABS_Y, 1.0 / (maxn + 1)));
		c = rnd.next(-lim / 2, lim / 2) / Q(poly1[rnd.next(0, (int)poly1.size() - 1)].get_den());
		poly1[0] += c;
		g = integer_points(poly1);
		okay = (int)g.size() >= maxn + 1;
		if (rnd.next(0, 1) != 0 && c.get_den() == 1) {
			okay = false;
		}
	}
	shuffle(f);
	shuffle(g);
	std::cout << maxn;
	if (!ans) {
		g.resize(maxn);
		int to_mod = rnd.next(1, (int)sqrt(maxn) + 1);
		std::set<int> mods;
		while ((int)mods.size() < to_mod) {
			mods.insert(rnd.next(0, maxn));
		}
		for (auto i : mods) {
			bool okay = false;
			auto &mod = g[i].second;
			int dy = 0;
			while (!okay) {
				dy = rnd.next(-49, 50);
				okay = mod + dy <= MAX_ABS_Y && mod + dy >= -MAX_ABS_Y;
			}
			mod += dy;
			bool mod_x = rnd.next(0, 2) == 0;
			if (mod_x) {
				int dx = 0;
				okay = false;
				while (!okay) {
					dx = rnd.next(-49, 50);
					okay = g[i].first + dx <= MAX_ABS_X && g[i].first + dx >= -MAX_ABS_X;
				}
				g[i].first += dx;
			}
		}
	}
	for (int i = 0; i <= maxn; i++) {
		std::cout << std::endl << f[i].first << " " << f[i].second;
	}
	for (int i = 0; i <= maxn; i++) {
		std::cout << std::endl << g[i].first << " " << g[i].second;
	}
	if (ans) {
		std::cerr << "    [Generator] Expected C = " << -c << std::endl;
	} else {
		std::cerr << "    [Generator] Expected NO " << std::endl;
	}
	return 0;
}