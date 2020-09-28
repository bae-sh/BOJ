#include<iostream>
#include<algorithm>
using namespace std;
int T, W;
int dp[1001][2][31];

int main() {
	cin >> T >> W;
	int *fruit = new int[T + 1];//1번부터 시작
	int a;
	for (int i = 1; i <= T; i++) {
		cin >> a;
		fruit[i] = a - 1;
	}


	for (int i = 1; i <= T; i++) {
		for (int j = 0; j <= W; j++) {
			if (fruit[i] == 0) {
				if (j == 0) {
					dp[i][0][j] = dp[i - 1][0][j] + 1;
					dp[i][1][j] = dp[i - 1][1][j];
				}
				else {
					dp[i][0][j] = max(dp[i - 1][0][j] + 1, dp[i - 1][1][j - 1] + 1);
					dp[i][1][j] = max(dp[i - 1][1][j], dp[i - 1][0][j - 1]);
				}
			}
			else {
				if (j == 0) {
					continue;
				}
				else {
					dp[i][0][j] = max(dp[i - 1][1][j - 1], dp[i - 1][0][j]);
					dp[i][1][j] = max(dp[i - 1][0][j - 1] + 1, dp[i - 1][1][j] + 1);
				}
			}
		}
	}
	int Max = 0;
	for (int i = 0; i <= W; i++) {
		Max = max(dp[T][0][i], Max);
		Max = max(dp[T][1][i], Max);
	}
	cout << Max;
}