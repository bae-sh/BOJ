#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int N, ans;
vector<int> v[10001];
int indegree[10001];
int cost[10001];//작업량
int dist[10001];//최종값
queue<int> q;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		int x, y; cin >> x >> y;
		cost[i] = x;
		for (int j = 0; j < y; j++) {
			int z; cin >> z;
			v[z].push_back(i);
			indegree[i]++;
		}
	}
	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0) {
			q.push(i);
			dist[i] = cost[i];
		}
	}

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (auto i : v[cur]) {
			indegree[i]--;
			dist[i] = max(dist[i], cost[i] + dist[cur]);
			if (indegree[i] == 0) {
				q.push(i);
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		ans = max(ans, dist[i]);
	}
	cout << ans;
}