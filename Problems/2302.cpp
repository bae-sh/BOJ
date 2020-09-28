#include<iostream>
using namespace std;
int dp[41]={1,1,2};
int n,m;
int ans = 1;
int main() {
	for (int i = 3; i < 41; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	cin >> n>>m;
	int *seat = new int[m+2];
	seat[0] = 0, seat[m + 1] = n+1;
	for (int i = 1; i <= m; i++) {
		cin >> seat[i];
	}
	for (int i = 0; i <= m; i++) {
		int num = seat[i + 1] - seat[i] - 1;
		ans *= dp[num];
	}
	cout << ans;
}