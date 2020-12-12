#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
int parent[50000];
bool check[50000];
int depth[50000];
int dist[50000];
int N, M;
vector<pair<int, int>> v[50000];
int lca(int u, int v) {
	if (depth[u] < depth[v]) {
		swap(u, v);
	}
	while (depth[u] != depth[v]) {
		u = parent[u];
	}
	while (u != v) {
		u = parent[u];
		v = parent[v];
	}
	return u;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int a, b, c; cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	check[1] = true;
	queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i].first;
			int cost = v[cur][i].second;
			if (!check[next]) {
				parent[next] = cur;
				depth[next] = depth[cur] + 1;
				dist[next] = dist[cur] + cost;
				check[next] = true;
				q.push(next);
			}
		}
	}
	int M; cin >> M;
	for (int i = 0; i < M; i++) {
		int u, v; cin >> u >> v;
		int p = lca(u, v);
		cout << dist[u] + dist[v] - 2 * dist[p] << "\n";
	}
}