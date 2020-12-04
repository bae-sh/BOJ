#include<iostream>
#include<vector>
#include<queue>
#define INF 987654321

using namespace std;
int n, m, a, b, c, s, e;
vector<pair<int, int>> v[1001];
int trace[1001];
int Dist[1001];
priority_queue<pair<int, int>> pq;
void print(int x, int dpt) {
	if (x == 0) {
		cout << dpt << "\n";
		return;
	}
	print(trace[x], dpt + 1);
	cout << x << " ";
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
	}
	cin >> s >> e;
	fill(Dist, Dist + 1001, INF);
	Dist[s] = 0;
	pq.push({ 0,s });
	while (!pq.empty()) {
		int cCost = -pq.top().first;
		int cur = pq.top().second; pq.pop();
		for (int i = 0; i < v[cur].size(); i++) {
			int nCost = v[cur][i].second;
			int next = v[cur][i].first;
			if (Dist[next] > cCost + nCost) {
				Dist[next] = cCost + nCost;
				pq.push({ -Dist[next],next });
				trace[next] = cur;
			}
		}
	}
	cout << Dist[e] << "\n";

	print(e, 0);
}