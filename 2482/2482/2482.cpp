#include<iostream>
#include<algorithm>
#include<cstring>
#define MOD 1000000003
using namespace std;
int N, K;
long long ans;
long long dp[1001][1001][2];//i번쨰에 j만큼 선택한 수 k 선택유뮤
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N >> K;
	dp[1][1][1] = 1;//pick first
	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			dp[i][j][0] = (dp[i - 1][j][1] + dp[i - 1][j][0]) % MOD;
			dp[i][j][1] = dp[i - 1][j - 1][0];
		}
	}
	ans += dp[N][K][0];
	memset(dp, 0, sizeof(dp));

	dp[1][0][0] = 1;//pick second
	for (int i = 2; i <= N; i++) {
		dp[i][0][0] = dp[i - 1][0][0];
		for (int j = 1; j <= K; j++) {
			dp[i][j][0] = (dp[i - 1][j][1] + dp[i - 1][j][0]) % MOD;
			dp[i][j][1] = dp[i - 1][j - 1][0];
		}
	}
	ans += dp[N][K][0] + dp[N][K][1];
	cout << ans %MOD;
}