#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int n, m, k;
vector<pair<int, int>> v[1001];
priority_queue<int> dist[1001];

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		v[a].push_back({ b,c, });
	}
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,1 });
	dist[1].push(0);

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second; pq.pop();

		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i].first;
			int nCost = v[cur][i].second;
			if (dist[next].size() < k || dist[next].top() > cost + nCost) {
				if (dist[next].size() == k) {
					dist[next].pop();
				}
				dist[next].push({ cost + nCost });
				pq.push({ -(cost + nCost),next });
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (dist[i].size() < k) {
			cout << -1 << "\n";
		}
		else {
			cout << dist[i].top() << "\n";
		}
	}
}