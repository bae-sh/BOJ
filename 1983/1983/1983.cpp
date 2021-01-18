#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int N;
vector<int> a;
vector<int> b;
int dp[401][401][401];//stage, use_a, use_b
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		int x; cin >> x;
		if (x != 0) {
			a.push_back(x);
		}
	}
	for (int i = 1; i <= N; i++) {
		int x; cin >> x;
		if (x != 0) {
			b.push_back(x);
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i && j <= a.size(); j++) {
			for (int k = 1; k <= i && k <= b.size(); k++) {
				int ans = dp[i - 1][j - 1][k - 1] + a[j - 1] * b[k - 1];
				if (k <= i - 1) {
					ans = max(ans, dp[i - 1][j - 1][k]);
				}
				if (j <= i - 1) {
					ans = max(ans, dp[i - 1][j][k - 1]);
				}
				if (j <= i - 1 && k <= i - 1) {
					ans = max(ans, dp[i - 1][j][k]);
				}
				dp[i][j][k] = ans;
			}
		}
	}
	cout << dp[N][a.size()][b.size()] << "\n";
}