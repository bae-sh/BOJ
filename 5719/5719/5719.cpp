#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string.h>
#define INF 987654321
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	while (1) {
		int n, m; cin >> n >> m;
		if (n == 0 && m == 0) break;
		int s, d; cin >> s >> d;
		int Dist[501];
		bool check[501][501];
		memset(check, 0, sizeof(check));

		for (int i = 0; i < 501; i++) {
			Dist[i] = INF;
		}
		vector<pair<int, int>> v[501];
		vector<pair<int, int>> r[501];
		for (int i = 0; i < m; i++) {
			int a, b, c; cin >> a >> b >> c;
			v[a].push_back({ b,c });
			r[b].push_back({ a,c });
		}
		priority_queue<pair<int, int>> pq;
		pq.push({ 0,s });
		Dist[s] = 0;
		while (!pq.empty()) {
			int cur = pq.top().second;
			int cost = -pq.top().first; pq.pop();
			for (auto x : v[cur]) {
				int next = x.first;
				int ncost = x.second;
				if (cost + ncost < Dist[next]) {
					Dist[next] = cost + ncost;
					pq.push({ -Dist[next], next });
				}
			}
		}
		queue<int> q;
		q.push(d);
		while (!q.empty()) {
			int cur = q.front(); q.pop();
			for (auto x : r[cur]) {
				int next = x.first;
				int ncost = x.second;
				if (Dist[next] == Dist[cur] - ncost && !check[next][cur]) {
					check[next][cur] = true;
					q.push(next);
				}
			}

		}
		for (int i = 0; i < 501; i++) {
			Dist[i] = INF;
		}
		pq.push({ 0,s });
		Dist[s] = 0;
		while (!pq.empty()) {
			int cur = pq.top().second;
			int cost = -pq.top().first; pq.pop();
			for (auto x : v[cur]) {
				int next = x.first;
				int ncost = x.second;
				if (cost + ncost < Dist[next] && !check[cur][next]) {
					Dist[next] = cost + ncost;
					pq.push({ -Dist[next], next });
				}
			}
		}
		if (Dist[d] == INF) {
			cout << "-1\n";
		}
		else {
			cout << Dist[d] << "\n";
		}
	}
}
