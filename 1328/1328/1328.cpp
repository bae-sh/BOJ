#include<iostream>
#define mod 1000000007 
using namespace std;
int N, M, L, R;
long long dp[101][101][101];

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> L >> R;
	dp[1][1][1] = 1;
	for (int i = 1; i <= N; i++) {
		for (int l = 1; l <= i; l++) {
			for (int r = 1; r <= i; r++) {
				dp[i + 1][l + 1][r] = (dp[i + 1][l + 1][r]+dp[i][l][r])%mod;
				dp[i + 1][l][r] = (dp[i + 1][l][r] + (dp[i][l][r] * (i - 1)) % mod) % mod;
				dp[i + 1][l][r + 1] = (dp[i + 1][l][r + 1] + dp[i][l][r]) % mod;
			}
		}
	}
	cout << dp[N][L][R] << "\n";
}