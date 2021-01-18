#include<iostream>
#define mod 1000000000
using namespace std;
int N;
long long dp[1000001];

int main() {
	cin >> N;
	dp[2] = 1;
	for (int i = 3; i <= 1000000; i++) {
		dp[i] = (dp[i - 1] * (i - 1) % mod + dp[i - 2] * (i - 1) % mod) % mod;
	}
	cout << dp[N] << "\n";
}