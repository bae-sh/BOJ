#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define INF 1000001LL*50000LL

using namespace std;
int N, M, K;
long long ans ;
long long Dist[10001][21];
vector<pair<int, int>> v[10001];
bool check[10001][21];
priority_queue<pair<long long, pair<int, int>>> pq;//cost,next,roadCost
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		int a, b, c; cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	for (int i = 2; i < 10001; i++) {
		for (int j = 0; j < 21; j++) {
			Dist[i][j] = INF;
		}
	}

	pq.push({ 0,{1,0} });
	while (!pq.empty()) {
		long long cost = -pq.top().first;
		int cur = pq.top().second.first;
		int roadCost = pq.top().second.second; pq.pop();
		if (cur == N) {
			ans = cost;
			break;
		}
		if (check[cur][roadCost]) {
			continue;
		}
		check[cur][roadCost] = true;
		for (int i = 0; i < v[cur].size(); i++) {
			long long nCost = v[cur][i].second;
			int next = v[cur][i].first;
			if (Dist[next][roadCost] > cost + nCost) {
				Dist[next][roadCost] = cost + nCost;
				pq.push({ -Dist[next][roadCost],{next,roadCost} });
			}
			if (roadCost<K && Dist[next][roadCost + 1]>cost) {
				Dist[next][roadCost + 1] = cost;
				pq.push({ -Dist[next][roadCost + 1],{next,roadCost + 1} });;
			}
		}
	}
	cout << ans;
}
