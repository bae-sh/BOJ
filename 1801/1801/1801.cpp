#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
bool dp[81][81][81][81];
int n;
int num[16];
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	dp[0][0][0][0] = true;
	for (int i = 0; i < n; i++) {
		for (int l1 = 80; l1 >= 0; l1--) {
			for (int l2 = 80; l2 >= 0; l2--) {
				for (int l3 = 80; l3 >= 0; l3--) {
					for (int l4 = 80; l4 >= 0; l4--) {
						if (!dp[l1][l2][l3][l4]) {
							continue;
						}
						if (l1 + num[i] <= 80) {
							dp[l1 + num[i]][l2][l3][l4] = true;
						}
						if (l2 + num[i] <= 80) {
							dp[l1][l2 + num[i]][l3][l4] = true;
						}
						if (l3 + num[i] <= 80) {
							dp[l1][l2][l3 + num[i]][l4] = true;
						}
						if (l4 + num[i] <= 80) {
							dp[l1][l2][l3][l4 + num[i]] = true;
						}
					}
				}
			}
		}
	}
	int ans = -1;
	for (int i = 1; i <= 80; i++) {
		for (int j = 1; j <= 80; j++) {
			if (dp[i][j][i][j]) {
				ans = max(ans, i * j);
			}
		}
	}
	cout << ans<<"\n";
}