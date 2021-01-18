#include<iostream>
#include<vector>
#include<map>
#include<string.h>
using namespace std;
int dx[] = { -1,-1,0,1,1,1,0,-1 };
int dy[] = { 0,1,1,1,0,-1,-1,-1 };
int N, L;
int m[20][20];
int dp[21][20][20][20][20];
int ans;
int go(int len, int x1, int y1, int x2, int y2) {
	if (len > L) {
		return 0;
	}
	if (len == L) {
		return 1;
	}
	if (dp[len][x1][y1][x2][y2] != -1) {
		return dp[len][x1][y1][x2][y2];
	}
	dp[len][x1][y1][x2][y2] = 0;

	for (int i = 0; i < 8; i++) {
		int nx1 = x1 + dx[i];
		int ny1 = y1 + dy[i];
		if (0 <= nx1 && nx1 < N && 0 <= ny1 && ny1 < N) {
			for (int j = 0; j < 8; j++) {
				int nx2 = x2 + dx[j];
				int ny2 = y2 + dy[j];
				if (0 <= nx2 && nx2 < N && 0 <= ny2 && ny2 < N) {
					if (m[nx1][ny1] == m[nx2][ny2]) {
						dp[len][x1][y1][x2][y2] += go(len + 2, nx1, ny1, nx2, ny2);
					}
				}
			}
		}
	}
	return dp[len][x1][y1][x2][y2];
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> m[i][j];
		}
	}
	memset(dp, -1, sizeof(dp));
	for (int x1 = 0; x1 < N; x1++) {
		for (int y1 = 0; y1 < N; y1++) {
			for (int k = 0; k < 8; k++) {
				int x2 = x1 + dx[k];
				int y2 = y1 + dy[k];
				if (0 <= x2 && x2 < N && 0 <= y2 && y2 < N) {
					if (m[x1][y1] == m[x2][y2]) {
						ans += go(2, x1, y1, x2, y2);
					}
				}
			}
			ans += go(1, x1, y1, x1, y1);
		}
	}
	cout << ans << "\n";

}