import queue

BIG = 1_000_000_000_000_000
 
n, m, k = map(int, input().split())
red_edges = [[] for _ in range(n + 3)]
blue_edges = [[] for _ in range(n + 3)]
 
for _ in range(m):
	u, v, w = map(int, input().split())
	red_edges[u].append((v, w))
	red_edges[v].append((u, w))
 
for _ in range(k):
	u, v, w = map(int, input().split())
	blue_edges[u].append((v, w))
	blue_edges[v].append((u, w))
 
def dijkstra(dp, start):
	qu = [(0, start, 0)]
	dp[start][0] = 0
	while qu:
		d, u, i = queue.heappop(qu)
		if dp[u][i] != d:
			continue
		for v, w in red_edges[u]:
			if dp[v][i] > d + w:
				dp[v][i] = d + w
				queue.heappush(qu, (d + w, v, i))
		if i != 0:
			continue
		for v, w in blue_edges[u]:
			if dp[v][i + 1] > d + w:
				dp[v][i + 1] = d + w
				queue.heappush(qu, (d + w, v, i + 1))
 

dp = [[BIG, BIG] for _ in range(n + 3)]
dijkstra(dp, 1)
ans = min(dp[2][0], dp[2][1])
print(ans if ans < 1_000_000_000_000_000 else -1)