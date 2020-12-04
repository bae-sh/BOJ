#include<iostream>
#include<vector>
#include<queue>

using namespace std;
int n, m, s, e, cnt;
bool used[10001][10001];
queue<int> p;
vector<pair<int, int>> v[10001];
vector<int> trace[10001];
int Dist[10001];
int indegree[10001];
void check(int to) {
	if (to == s) return;
	for (int i = 0; i < trace[to].size(); i++) {
		int from = trace[to][i];
		if (!used[from][to]) {
			cnt++;
			used[from][to] = true;
			check(from);
		}
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		v[a].push_back({ b,c });
		indegree[b]++;
	}
	cin >> s >> e;
	p.push(s);
	while (!p.empty()) {
		int cur = p.front(); p.pop();
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i].first;
			int cost = v[cur][i].second;
			indegree[next]--;
			if (Dist[cur] + cost > Dist[next]) {
				Dist[next] = Dist[cur] + cost;
				trace[next].clear();
				trace[next].push_back(cur);
			}
			else if (Dist[cur] + cost == Dist[next]) {
				trace[next].push_back(cur);
			}
			if (indegree[next] == 0) {
				p.push(next);
			}
		}
	}

	check(e);
	cout << Dist[e] << "\n";
	cout << cnt;
}