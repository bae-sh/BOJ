#include<iostream>
#include<string.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cout.tie(0); cin.tie(0);

	while (1) {
		int N; cin >> N;
		if (N == 0) {
			break;
		}
		long long dp[41][41]; memset(dp, 0, sizeof(dp));
		dp[N][0] = 1;
		for (int i = N - 1; i >= 0; i--) {
			for (int j = N; j > 0; j--) {
				dp[i][j] = dp[i + 1][j - 1] + dp[i][j + 1];
			}
			dp[i][0] = dp[i][1];
		}
		
		cout << dp[0][0] << "\n";
	}
}