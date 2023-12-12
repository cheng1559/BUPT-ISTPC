#include "testlib.h"
#include <set>

int main(int argc, char *argv[]) {
	registerValidation(argc, argv);
	int n = inf.readInt(3, 200'000, "n");
	inf.readSpace();
	int m = inf.readInt(0, (int)std::min(200'000ll, (long long)(n + 1) * (n + 2) / 2), "m");
	inf.readSpace();
	int k = inf.readInt(0, (int)std::min(200'000ll, (long long)(n + 1) * (n + 2) / 2), "k");
	quitif(m + k < 2 || m + k > (int)std::min(200'000ll, (long long)(n + 1) * (n + 2) / 2), _fail, "m + k must be in [2, (n + 1) * (n + 2) / 2]");
	inf.readEoln();
	std::set<std::pair<int, int>> edges;
	for (int i = 0; i < m + k; i++) {
		int u = inf.readInt(1, n + 2, "~u_i~");
		inf.readSpace();
		int v = inf.readInt(1, n + 2, "~v_i~");
		inf.readSpace();
		inf.readInt(0, 10000, "w_i");
		quitif(u >= v, _fail, "edges must be expressed as (u, v) with u < v");
		quitif(edges.count({u, v}), _fail, "duplicated edge %d %d", u, v);
		edges.insert({u, v});
		inf.readEoln();
	}
	inf.readEof();
	return 0;
}