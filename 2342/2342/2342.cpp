#include<iostream>
#include<queue>
#include<algorithm>
#include<string.h>
#include<cmath>
#define INF 987654321
using namespace std;
vector<int> order;
int dp[100001][5][5];//현재 단계, 왼발 오른발 에서 끝까지 갈떄까지의 최소값
int dfs(int cur,int x,int y) {
	int& ans = dp[cur][x][y];
	if (ans != INF) {
		return ans;
	}
	if (cur == order.size()) {
		return 0;
	}
	int pos = order[cur];
	if (pos == x) {
		ans = min(ans, dfs(cur + 1, pos, y) + 1);
	}
	else if (x == 0) {
		ans = min(ans, dfs(cur + 1, pos, y) + 2);
	}
	else {
		if (abs(pos - x) == 2) {
			ans = min(ans, dfs(cur + 1, pos, y) + 4);
		}
		else {
			ans = min(ans, dfs(cur + 1, pos, y) + 3);
		}
	}

	if (pos == y) {
		ans = min(ans, dfs(cur + 1, x, pos) + 1);
	}
	else if (y == 0) {
		ans = min(ans, dfs(cur + 1, x, pos) + 2);
	}
	else {
		if (abs(pos - y) == 2) {
			ans = min(ans, dfs(cur + 1, x, pos) + 4);
		}
		else {
			ans = min(ans, dfs(cur + 1, x, pos) + 3);
		}
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	while (true) {
		int x; cin >> x;
		if (x == 0) break;
		order.push_back(x);
	}
	
	for (int i = 0; i < 100001; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				dp[i][j][k] = INF;
			}
		}
	}
	if (order.empty()) {
		dp[0][0][0] = 0;
	}
	dfs(0, 0, 0);
	cout << dp[0][0][0] << "\n";
}