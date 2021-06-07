#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
 
string s;
int dp[500][500];
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> s;
	for (int i = 1; i < s.length(); i++) {//len
		for (int j = 0; j < s.length() - i; j++) {//start
			for (int k = j; k < s.length() - 1; k++) {//mid
				dp[j][j + i] = max(dp[j][j + i], dp[j][k] + dp[k + 1][j + i]);
			}
			if ((s[j] == 'a' && s[j + i] == 't') || (s[j] == 'g' && s[j + i] == 'c')) {
				dp[j][j + i] = max(dp[j][j + i], dp[j + 1][j + i - 1] + 2);
			}
		}
	}
	cout << dp[0][s.length() - 1] << "\n";
}