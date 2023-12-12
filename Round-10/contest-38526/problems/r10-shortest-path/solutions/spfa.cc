#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <limits>
#include <tuple>
#include <optional>
#include <cmath>

template<typename T> int len(const T &x) { return (int)x.size(); }
template<typename T, int S> int len(const T (&)[S]) { return S; }
[[maybe_unused]] static inline constexpr struct {
	template <typename T> constexpr operator T() const { return std::numeric_limits<T>::max(); }
} BIG;

using ll = long long;
using namespace std;

static void solve(void);

int main(void) {
	cin.tie(nullptr), cout.tie(nullptr);
	ios::sync_with_stdio(false);

	ll t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}

void spfa(int s, const vector<vector<pair<int, int>>> &g, vector<ll> &d) {
	d[s] = 0;
	queue<int> q;
	q.push(s);
	vector<bool> inq(len(g));
	inq[s] = true;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		inq[u] = false;
		for (auto [v, w] : g[u]) {
			if (d[v] > d[u] + w) {
				d[v] = d[u] + w;
				if (!inq[v]) {
					q.push(v);
					inq[v] = true;
				}
			}
		}
	}
}

static void solve(void) {
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<pair<int, int>>> g(n + 3);
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].emplace_back(v, w);
		g[v].emplace_back(u, w);
	}
	vector<ll> d1(n + 3, (int)BIG);
	vector<ll> d2(n + 3, (int)BIG);
	spfa(1, g, d1);
	spfa(2, g, d2);
	ll ans = d1[2];
	for (int i = 0; i < k; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		ans = min(ans, d1[u] + d2[v] + w);
		ans = min(ans, d1[v] + d2[u] + w);
	}
	cout << (ans >= (int)BIG ? -1 : ans) << endl;
}