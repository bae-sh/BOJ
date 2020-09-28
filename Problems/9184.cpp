#include<iostream>
using namespace std;
int n, m, k,x,y;
int dp[15][15] = {1};
int main() {
	cin >> n >> m >> k;
	if (k == 0) {
		x = n - 1;
		y = m - 1;
	}
	else {
		x = (k-1) / m;
		y = k - x * m - 1;
	}
	for (int i = 0; i <= x; i++) {
		for (int j = 0; j <= y; j++) {
			if (i != 0) {
				dp[i][j] += dp[i - 1][j];
			}
			if (j != 0) {
				dp[i][j] += dp[i][j - 1];
			}
		}
	}
	for (int i = x; i < n; i++) {
		for (int j = y; j < m; j++) {
			if (i != x) {
				dp[i][j] += dp[i - 1][j];
			}
			if (j != y) {
				dp[i][j] += dp[i][j - 1];
			}
		}
	}
	cout << dp[n - 1][m - 1];
}