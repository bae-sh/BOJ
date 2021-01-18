#include<iostream>
#include<algorithm>
#define INF -987654321
using namespace std;
int N, M;
int s[101];
int dp[101][101];
bool check[101][101];
int go(int n, int m) {
	if (m == 0) return 0;
	if (n <= 0) return INF;
	if (check[n][m]) return dp[n][m];
	check[n][m] = true;
	int ans = go(n - 1, m); 
	for (int i = 1; i <= n; i++) {
		ans = max(ans, go(i - 2, m - 1) + s[n] - s[i - 1]);
	}
	return dp[n][m] = ans;
}
int main() {
	ios::sync_with_stdio(false); cout.tie(0); cin.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		int x; cin >> x;
		s[i] = s[i - 1] + x;
	}
	cout << go(N, M) << "\n";
}