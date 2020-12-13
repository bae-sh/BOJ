#include<iostream>
#include<algorithm>
#include<queue>
#include<string.h>
using namespace std;
int N, K;
queue<int> q;
int cost[100001];
int ans = -1;
int cnt;
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> K;
	memset(cost, -1, sizeof(cost));
	cost[N] = 0;
	q.push(N);
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		if (cur == K) {
			if (ans == -1 || ans == cost[cur]) {
				ans = cost[cur];
				cnt++;
				continue;
			}
		}
		for (int y : {cur - 1, cur + 1, cur * 2}) {
			int next_cost = cost[cur] + 1;
			if (0 <= y && y <= 100000) {
				if (cost[y] == -1 || cost[y] >= next_cost) {
					cost[y] = next_cost;
					q.push(y);
				}
			}
		}
	}
	cout << ans << "\n" << cnt;
}