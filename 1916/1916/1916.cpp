#include<iostream>
#include<vector>
#include<queue>
#define INF 987654321

using namespace std;
int Dist[1001];
int N, M, s, e;
priority_queue<pair<int, int>> pq;
vector<pair<int, int>> v[1001];

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c; cin >> a >> b >> c;
		v[a].push_back({ b,c });
	}
	cin >> s >> e;
	fill(Dist, Dist + 1001, INF);
	Dist[s] = 0;
	pq.push({ 0,s });
	while (!pq.empty()) {
		int cCost = -pq.top().first;
		int cur = pq.top().second; pq.pop();
		if (Dist[cur] < cCost) continue;
		for (int i = 0; i < v[cur].size(); i++) {
			int nCost = v[cur][i].second;
			int next = v[cur][i].first;
			if (Dist[next] > cCost + nCost) {
				Dist[next] = cCost + nCost;
				pq.push({ -Dist[next],next });
			}
		}
	}
	cout << Dist[e];
}