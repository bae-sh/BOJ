#include<iostream>
using namespace std;
int t;
int dp[40][40][15];
int dx[] = { 0,1,1,0,-1,-1 };
int dy[] = { 1,0,-1,-1,0,1 };
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> t;
	dp[14][14][0] = 1;
	for (int k = 1; k <= 14; k++) {//ÀÌµ¿È½¼ö
		for (int i = 0; i < 29; i++) {
			for (int j = 0; j < 29; j++) {
				for (int l = 0; l < 6; l++) {
					int nx = i + dx[l];
					int ny = j + dy[l];
					if (0 <= nx && nx < 30 && 0 <= ny && ny < 30) {
						dp[nx][ny][k] += dp[i][j][k - 1];
					}
				}
			}
		}
	}
	while (t--) {
		int n; cin >> n;
		cout << dp[14][14][n] << "\n";
	}
}