#include <iostream>
const int Max = 1000000;
const int Mod = 15746;

int main() {
	using namespace std;
	int n;
	cin >> n;
	int *dp = new int[Max];
	dp[1] = 1, dp[2] = 2;
	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i-2]%Mod+dp[i-1]%Mod)%Mod;
	}
	cout << dp[n];
}