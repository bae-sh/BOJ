/*#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N, M, K;
vector<pair<int, int>> v[301];
int Dist[301][301];//num °ú cost
priority_queue < pair<int, pair<int, int>>> pq; // score,pos,cnt
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> M >> K;
	for (int i = 0; i < K; i++) {
		int a, b, c; cin >> a >> b >> c;
		if (a < b) {
			v[a].push_back({ b,c });
		}
	}
	pq.push({ 0,{1,1} });
	while (!pq.empty()) {
		int cost = pq.top().first;
		int cur = pq.top().second.first;
		int cnt = pq.top().second.second; pq.pop();
		if (cnt == M) {
			continue;
		}
		for (auto x : v[cur]) {
			int next = x.first;
			int nCost = x.second;
			if (Dist[next][cnt + 1] < cost + nCost) {
				Dist[next][cnt + 1] = cost + nCost;
				pq.push({ Dist[next][cnt + 1], { next,cnt + 1 } });
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= M; i++) {
		ans = max(ans, Dist[N][i]);
	}
	cout << ans << "\n";
}*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int N, M, K;
int dp[301][301];//cur,cost
vector<pair<int, int>> v[301];//from cost to
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> M >> K;
	for (int i = 0; i < K; i++) {
		int a, b, c; cin >> a >> b >> c;
		if (a < b) {
			if (a == 1) {
				dp[b][2] = max(dp[b][2], c);
			}
			else {
				v[b].push_back({ a,c });
			}
		}
	}
	for (int i = 2; i <= N; i++) {//to
		for (int j = 3; j <= M; j++) {//cnt
			for (auto x : v[i]) {
				int from = x.first;
				int cost = x.second;
				if (dp[from][j - 1] == 0) continue;
				dp[i][j] = max(dp[from][j - 1] + cost, dp[i][j]);
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= M; i++) {
		ans = max(ans, dp[N][i]);
	}
	cout << ans << "\n";
}