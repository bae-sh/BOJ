#include<iostream>
#include<algorithm>
#include<string.h>
#define INF 987654321
using namespace std;
int N, M, a, b, X, Y;
int dp[501][101];//n번 줄까지 고려했을떄 m까지 가는 거리
int line[501];
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> M >> a >> b >> X >> Y;
	for (int i = 1; i <= M; i++) {
		cin >> line[i];
	}
	for (int i = 0; i <= M; i++) {
		for (int j = 0; j <= N; j++) {
			dp[i][j] = INF;
		}
	}
	for (int i = 1; i <= N; i++) {
		if (a == i) {
			dp[0][i] = 0;
		}
		else {
			dp[0][i] = abs(i - a) * Y;
		}
	}
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				if (j == k && (line[i] == k || line[i] == k - 1)) {
					dp[i][k] = min(dp[i][k], dp[i - 1][j] + X);
				}
				else if ((j <= line[i] && line[i] <= k - 1) || (k <= line[i] && line[i] <= j - 1)) {
					dp[i][k] = min(dp[i][k], dp[i - 1][j] + (abs(j - k) - 1) * Y);
				}
				else {
					dp[i][k] = min(dp[i][k], dp[i - 1][j] + abs(j - k) * Y);
				}
			}
		}
	}
	cout << dp[M][b] << "\n";
}