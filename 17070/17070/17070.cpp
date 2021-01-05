#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
int n;
int map[16][16];
int dp[16][16][16][16];//꼬리 머리

int dfs(int x1, int y1, int x2, int y2) {//꼬리 머리
	int& ans = dp[x1][y1][x2][y2];
	if (ans != -1) {
		return ans;
	}
	if ((x2 == n - 1) && (y2 == n - 1)) {
		return 1;
	}

	ans = 0;
	if (x1 == x2) {//가로
		int nx1 = x1; int ny1 = y1 + 1; int nx2 = x2; int ny2 = y2 + 1;
		if (0 <= ny2 && ny2 < n && map[nx2][ny2] == 0) {
			ans += dfs(nx1, ny1, nx2, ny2);
			nx2 = x2 + 1;
			if (0 <= nx2 && nx2 < n && map[nx2][ny2] == 0 && map[nx2][ny1] == 0) {
				ans += dfs(nx1, ny1, nx2, ny2);
			}
		}
	}
	else if (y1 == y2) {//세로
		int nx1 = x1 + 1; int ny1 = y1; int nx2 = x2 + 1; int ny2 = y2;
		if (0 <= nx2 && nx2 < n && map[nx2][ny2] == 0) {
			ans += dfs(nx1, ny1, nx2, ny2);
			ny2 = y2 + 1;
			if (0 <= ny2 && ny2 < n && map[nx2][ny2] == 0 && map[nx1][ny2] == 0) {
				ans += dfs(nx1, ny1, nx2, ny2);
			}
		}
	}
	else {//대각선
		int nx1 = x1 + 1; int ny1 = y1 + 1; int nx2 = x2 + 1; int ny2 = y2;
		if (0 <= nx2 && nx2 < n && map[nx2][ny2] == 0) {
			ans += dfs(nx1, ny1, nx2, ny2);
		}
		nx2 = x2; ny2 = y2 + 1;
		if (0 <= ny2 && ny2 < n && map[nx2][ny2] == 0) {
			ans += dfs(nx1, ny1, nx2, ny2);
		}
		nx2 = x2 + 1;
		if (0 <= nx2 && nx2 < n && 0 <= ny2 && ny2 < n && map[nx2][ny2] == 0 && map[nx1][ny2] == 0 && map[nx2][ny1] == 0) {
			ans += dfs(nx1, ny1, nx2, ny2);
		}
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	memset(dp, -1, sizeof(dp));
	dfs(0, 0, 0, 1);
	if (dp[0][0][0][1] == -1) {
		cout << 0 << "\n";
	}
	else {
		cout << dp[0][0][0][1] << "\n";
	}
}