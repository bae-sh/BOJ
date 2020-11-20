#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define INF 987654321
using namespace std;

vector<pair<int, pair<int, int>>> vec[101];//next,cost,time
int Dist[101][10001];
void dijkstra(int N, int Cost_Max) {
	priority_queue<pair<int, pair<int, int>>> pq;//time next cost
	Dist[1][0] = 0;
	pq.push({ 0, { 1,0 } });
	while (!pq.empty()) {
		int cTimeCost = -pq.top().first;
		int cur = pq.top().second.first;
		int cCost = pq.top().second.second;
		pq.pop();
		if (Dist[cur][cCost] < cTimeCost) {
			continue;
		}
		for (int i = 0; i < vec[cur].size(); i++) {
			int nTimeCost = cTimeCost + vec[cur][i].second.second;
			int next = vec[cur][i].first;
			int nCost = cCost + vec[cur][i].second.first;
			if (nCost > Cost_Max) {
				continue;
			}
			if (Dist[next][nCost] > nTimeCost) {
				for (int j = nCost; j <= Cost_Max; j++) {
					if (Dist[next][j] > nTimeCost) {
						Dist[next][j] = nTimeCost;
					}
				}
				pq.push({ -Dist[next][nCost],{next,nCost} });
			}
		}
	}
	int ans = INF;
	for (int i = 1; i <= Cost_Max; i++) {
		ans = min(ans, Dist[N][i]);
	}
	if (ans == INF) {
		cout << "Poor KCM" << "\n";
	}
	else {
		cout << ans << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int T; cin >> T;
	while (T-- > 0) {
		int N, M, K; cin >> N >> M >> K;
		for (int i = 0; i < 101; i++) {//reset
			while (!vec[i].empty()) {
				vec[i].pop_back();
			}
		}
		for (int i = 0; i < K; i++) {
			int u, v, c, d; cin >> u >> v >> c >> d;
			vec[u].push_back({ v,{c,d} });
		}
		for (int i = 0; i <= N; i++) {
			for (int j = 0; j <= M; j++) {
				Dist[i][j] = INF;
			}
		}
		dijkstra(N, M);
	}
}