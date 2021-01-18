#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
int dp[50001];

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	
	cin >> n;
	for (int i = 1; i <= 50000; i++) {
		dp[i] = 5;
		for (int j = 1; j * j <= i; j++) {
			dp[i] = min(dp[i], dp[i - j * j] + 1);
		}
	}
	cout << dp[n] << "\n";
}