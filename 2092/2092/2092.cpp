#include<iostream>
#define mod 1000000
using namespace std;
int T, A, S, B;
int num[201];
long long dp[201][4001]; //사용한 값 자리수
long long ans;
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> T >> A >> S >> B;

	for (int i = 0; i < A; i++) {
		int x; cin >> x;
		num[x]++;
	}
	dp[0][0] = 1;
	for (int i = 1; i <= T; i++) {
		dp[i][0] = 1;
		for (int j = 1; j <= B; j++) {
			for (int k = 0; k <= num[i] && j - k >= 0; k++) {
				dp[i][j] += dp[i - 1][j - k];
				dp[i][j] %= mod;
			}
		}
	}
	for (int i = S; i <= B; i++) {
		ans += dp[T][i];
		ans %= mod;
	}
	cout << ans << "\n";
}