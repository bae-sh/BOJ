#include<iostream>
#include<algorithm>
using namespace std;
int n;
int room[1001];
int dp[1001];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> room[i];
		dp[i] = 1000;
	}
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		int jump = room[i];
		for (int j = i + 1; j <= i + jump&&j<n; j++) {
			dp[j] = min(dp[j], dp[i] + 1);
		}
	}
	if (dp[n-1] == 1000) {
		cout << -1;
	}
	else {
		cout << dp[n-1];
	}
}