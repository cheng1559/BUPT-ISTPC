import queue

BIG = 1_000_000_000_000_000
 
n, m, k = map(int, input().split())
red_edges = [[] for _ in range(n + 3)]
blue_edges = []
 
for _ in range(m):
	u, v, w = map(int, input().split())
	red_edges[u].append((v, w))
	red_edges[v].append((u, w))
 
for _ in range(k):
	u, v, w = map(int, input().split())
	blue_edges.append((u, v, w))
 
def dijkstra(dp, start):
	qu = [(0, start)]
	dp[start] = 0
	while qu:
		d, u = queue.heappop(qu)
		if dp[u] != d:
			continue
		for v, w in red_edges[u]:
			if dp[v] > d + w:
				dp[v] = d + w
				queue.heappush(qu, (d + w, v))
 
dp1 = [BIG] * (n + 3)
dp2 = [BIG] * (n + 3)
dijkstra(dp1, 1)
dijkstra(dp2, 2)
 
ans = dp1[2]
for u, v, w in blue_edges:
	ans = min(ans, dp1[u] + dp2[v] + w, dp1[v] + dp2[u] + w)
print(ans if ans < BIG else -1)