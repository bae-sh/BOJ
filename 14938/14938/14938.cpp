#include<iostream>
#include<algorithm>
#define INF 987654321
using namespace std;
int n, m, r;
int map[100];
bool check[100];
int dp[100][100];
int ans;
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m >> r;
	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dp[i][j] = INF;
		}
		dp[i][i] = 0;
	}
	for (int i = 0; i < r; i++) {
		int a, b, c; cin >> a >> b >> c;
		dp[a - 1][b - 1] = c;
		dp[b - 1][a - 1] = c;
	}
	int ans = 0;
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (dp[i][k] + dp[k][j] < dp[i][j]) {
					dp[i][j] = dp[i][k] + dp[k][j];
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		int temp = 0;
		for (int j = 0; j < n; j++) {
			if (dp[i][j] <= m) {
				temp += map[j];
			}
		}
		ans = max(ans, temp);
	}
	cout << ans << "\n";
}