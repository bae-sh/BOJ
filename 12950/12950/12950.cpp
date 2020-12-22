#include<iostream>
#include<vector>
#include<string.h>
#define INF 987654321
using namespace std;
int N, M;
int dp[20][20];
int ans = -1;
int cost[20][20];
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			dp[i][j] = INF;
		}
		dp[i][i] = 0;
	}
	for (int i = 0; i < M; i++) {
		int a, b; char c; cin >> a >> b >> c;
		dp[a][b] = 1;
		dp[b][a] = 1;
		cost[a][b] = c - 'a' + 1;
		cost[b][a] = c - 'a' + 1;
	}
	//i>ii ... jj>j
	for (int l = 2; l <= 400; l++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				for (int ii = 0; ii < N; ii++) {
					for (int jj = 0; jj < N; jj++) {
						if (cost[i][ii] == 0 || cost[jj][j] == 0) {
							continue;
						}
						if (cost[i][ii] == cost[jj][j]) {
							dp[i][j] = min(dp[i][j], dp[ii][jj] + 2);
						}
					}
				}
			}
		}
	}
	if (dp[0][1] == INF) {
		cout << -1 << "\n";
	}
	else {
		cout << dp[0][1] << "\n";
	}
}