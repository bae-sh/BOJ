#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int N, M;
int p[100001][18];
int depth[100001];
queue<int> q;
vector<int> v[100001];
int lca(int u,int v) {
	if (depth[u] < depth[v]) {
		swap(u, v);
	}
	int k = 0;
	while (depth[u] - (1 << (k + 1)) >= 0) {
		k++;
	}
	for (int i = k; i >= 0; i--) {
		if (depth[u] - (1 << i) >= depth[v]) {
			u = p[u][i];
		}
	}
	if (u == v) {
		return u;
	}
	for (int i = k; i >= 0; i--) {
		if (p[u][i] != 0 && p[u][i] != p[v][i]) {
			u = p[u][i];
			v = p[v][i];
		}
	}
	return p[u][0];
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	q.push(1);
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (int x : v[cur]) {
			if (x != 1 && depth[x] == 0) {
				depth[x] = depth[cur] + 1;
				p[x][0] = cur;
				q.push(x);
			}
		}
	}
	for (int j = 1; (1 << j) < N; j++) {
		for (int i = 1; i <= N; i++) {
			if (p[i][j - 1] != 0) {
				p[i][j] = p[p[i][j - 1]][j - 1];
			}
		}
	}
	cin >> M;
	while (M--) {
		int u, v; cin >> u >> v;
		cout << lca(u, v) << "\n";
	}
}