#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<queue>
#define INF 987654321
using namespace std;

int V, E;
vector<pair<int,int>> v[401];//value
int Dist[401][401];
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int a, b, c; cin >> a >> b >> c;
		v[a].push_back({ b,c });
	}
	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			if (i == j) {
				Dist[i][i] = 0;
			}
			else {
				Dist[i][j] = INF;
			}
		}
	}
	//다익스트라
	for (int i = 1; i <= V; i++) {
		priority_queue<pair<int, int>> pq;
		pq.push({ 0, i });
		while (!pq.empty()) {
			int cur = pq.top().second;
			int cCost = -pq.top().first;
			pq.pop();
			for (int j = 0; j < v[cur].size(); j++) {
				int next = v[cur][j].first;
				int nCost = cCost + v[cur][j].second;
				if (Dist[i][next] > nCost) {
					Dist[i][next] = nCost;
					pq.push({-nCost, next });
				}
			}
		}
	}

	int ans = INF;
	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			if (Dist[i][j] + Dist[j][i] != 0) {
				ans = min(ans, Dist[i][j] + Dist[j][i]);
			}
		}
	}
	if (ans == INF) {
		cout << -1;
	}
	else {
		cout << ans;
	}
}