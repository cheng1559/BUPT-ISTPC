#include "testlib.h"
#include <functional>
#include <set>
 
int main(int argc, char *argv[]) {
	registerValidation(argc, argv);
	int n = inf.readInt(2, 100'000, "n");
	inf.readSpace();
	int m = inf.readInt(1, (int)std::min(100'000ll, (long long)n * (n - 1) / 2), "~m~");
	inf.readEoln();
	std::vector<int> dsu;
	std::set<std::pair<int, int>> edges;
	for (int i = 0; i <= n; ++i) {
		dsu.push_back(i);
	}
	std::function<int(int)> find = [&](int x) { return dsu[x] == x ? x : dsu[x] = find(dsu[x]); };
	for (int i = 0; i < m; ++i) {
		int u = inf.readInt(1, n, "~u~");
		inf.readSpace();
		int v = inf.readInt(1, n, "~v~");
		inf.readEoln();
		quitif(u >= v, _fail, "Edges must be expressed in (u, v), where u < v");
		quitif(edges.count({u, v}), _fail, "Edges must be unique");
		edges.insert({u, v});
		u = find(u), v = find(v);
		if (u != v) {
			dsu[u] = v;
		}
	}
	int r = find(1);
	for (int i = 2; i <= n; ++i) {
		quitif(find(i) != r, _fail, "The graph must be connected");
	}
	inf.readEof();
	return 0;
}
