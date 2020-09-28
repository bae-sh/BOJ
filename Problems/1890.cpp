#include<iostream>
using namespace std;
int jump[100][100];
long long dp[100][100];
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> jump[i][j];
		}
	}
	dp[0][0] = 1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == n-1 && j == n-1) {
				break;
			}
			int dx = i + jump[i][j];
			int dy = j + jump[i][j];
			if (0 <= dx&&dx < n) {
				dp[dx][j] += dp[i][j];
			}
			if (0 <= dy && dy < n) {
				dp[i][dy] += dp[i][j];
			}
		}
	}
	cout << dp[n-1][n-1];

}