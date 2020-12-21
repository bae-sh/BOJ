#include<iostream>
#include<string>
using namespace std;
int dp[101][21][2];//현재 위치, 현재상태, 위아래
string a, b;
int ans;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	string s; cin >> s >> a >> b;
	for (int i = 1; i <= a.size(); i++) {
		char ca = a[i - 1];
		char cb = b[i - 1];
		if (i == 1) {
			if (ca == s[0]) {
				dp[i][1][0] = 1;
			}
			if (cb == s[0]) {
				dp[i][1][1] = 1;
			}
			continue;
		}

		for (int j = 1; j < i; j++) {
			for (int k = 1; k <= i && k <= s.size(); k++) {//현재 상태
				if (ca == s[k - 1]) {
					if (k == 1) {
						dp[i][1][0] = 1;
					}
					else {
						dp[i][k][0] += dp[j][k - 1][1];
					}
				}
				if (cb == s[k - 1]) {
					if (k == 1) {
						dp[i][1][1] = 1;
					}
					else {
						dp[i][k][1] += dp[j][k - 1][0];
					}
				}
			}
		}
		
		ans += dp[i][s.size()][0] + dp[i][s.size()][1];
	}
	cout << ans << "\n";
}