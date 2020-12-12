#include<iostream>
#define INF 987654321
using namespace std;
int N, M;
int dp[101][101];
int ans = INF, m;
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			dp[i][j] = INF;
		}
	}
	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		dp[a][b] = 1; dp[b][a] = 1;
	}
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (dp[i][j] > dp[i][k] + dp[k][j]) {
					dp[i][j] = dp[i][k] + dp[k][j];
				}
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		int temp = 0;
		for (int j = 1; j <= N; j++) {
			if (i == j) continue;
			temp += dp[i][j];
		}
		if (ans > temp) {
			ans = temp; m = i;
		}
	}
	cout << m;
}