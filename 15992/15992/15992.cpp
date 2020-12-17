#include<iostream>
#include<string.h>
#define mod 1000000009
using namespace std;
int T;	
long long dp[1001][1001];
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> T;
	dp[1][1] = 1; dp[2][1] = 1; dp[2][2] = 1; dp[3][1] = 1;
	for (int i = 3; i <= 1000; i++) {
		for (int j = 2; j <= i; j++) {
			dp[i][j] = dp[i - 3][j - 1] + dp[i - 2][j - 1] + dp[i - 1][j - 1];
			dp[i][j] %= mod;
		}
	}
	while (T--) {
		int a, b; cin >> a >> b;
		long long ans = 0;
		for(int i=1;i<=b;i++){
			ans = (ans + dp[a][i]) % mod;
		}
		cout << ans << "\n";
	}
}