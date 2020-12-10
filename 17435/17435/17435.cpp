#include<iostream>
using namespace std;

int dp[200001][20];

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int m; cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> dp[i][0];
	}
	for (int j = 1; j < 20; j++) {
		for (int i = 1; i <= m; i++) {
			dp[i][j] = dp[dp[i][j - 1]][j - 1];
		}
	}

	int q; cin >> q;
	while (q--) {
		int n, x; cin >> n >> x;
		for (int i = 0; i < 20; i++) {
			if (n & (1 << i)) {
				x = dp[x][i];
			}
		}
		cout << x << "\n";
	}
}