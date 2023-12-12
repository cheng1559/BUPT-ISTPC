import queue
 
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
	qu = queue.PriorityQueue()
	qu.put((0, start))
	dp[start] = 0
	while not qu.empty():
		d, u = qu.get()
		if dp[u] != d:
			continue
		for v, w in red_edges[u]:
			if dp[v] > dp[u] + w:
				dp[v] = dp[u] + w
				qu.put((dp[v], v))
 
dp1 = [1_000_000_000_000_000] * (n + 3)
dijkstra(dp1, 1)

ans = dp1[2]
print(ans if ans < 1_000_000_000_000_000 else -1)
