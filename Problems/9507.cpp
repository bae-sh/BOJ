#include<iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	long long ans[68];
	long long dp[68];
	dp[0] = 1; dp[1] = 1; dp[2] = 2; dp[3] = 4;
	for (int i = 4; i < 68; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4];
	}
	for (int i = 0; i < t; i++) {
		int x;
		cin >> x;
		ans[i] = dp[x];
	}
	for (int i = 0; i < t; i++) {
		cout << ans[i] << "\n";
	}

}