#include<iostream>
#include<algorithm>
#include<string.h>
#define INF 987654321
using namespace std;
int N;
int block[50];
int dp[50][250001];
int go(int cnt, int diff) {
	if (diff > 250000) {
		return -INF;
	}
	if (cnt == N) {
		if (diff == 0) {
			return 0;
		}
		else {
			return -INF;
		}
	}
	if (dp[cnt][diff] != -1) {
		return dp[cnt][diff];
	}
	dp[cnt][diff] = go(cnt + 1, diff);
	dp[cnt][diff] = max(dp[cnt][diff], go(cnt + 1, diff + block[cnt]));
	if (diff > block[cnt]) {
		dp[cnt][diff] = max(dp[cnt][diff], block[cnt] + go(cnt + 1, diff - block[cnt]));
	}
	else {
		dp[cnt][diff] = max(dp[cnt][diff], diff + go(cnt + 1, block[cnt] -diff));
	}
	return dp[cnt][diff];
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		 cin >> block[i];
	}
	memset(dp, -1, sizeof(dp));
	int MAX = go(0, 0);
	if (MAX == 0) {
		cout << -1 << "\n";
	}
	else {
		cout << MAX << "\n";
	}
}