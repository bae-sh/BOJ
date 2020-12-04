#include<iostream>
#define INF 987654321

using namespace std;
int dp[101][101];
int N;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int a; cin >> a;
			if (a == 1) {
				dp[i][j] = 1;
			}
			else {
				dp[i][j] = INF;
			}
		}
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (dp[i][j] > dp[i][k] + dp[k][j]) {
					dp[i][j] = dp[i][k] + dp[k][j];
				}
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (dp[i][j] == INF) {
				cout << "0 ";
			}
			else {
				cout << "1 ";
			}
		}
		cout << "\n";
	}
}