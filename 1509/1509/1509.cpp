#include<iostream>
#include<string>
#include<algorithm>
#define INF 987654321
using namespace std;
long long dp[2501];
bool check(string s) {
	for (int i = 0; i < s.length() / 2; i++) {
		if (s[i] != s[s.length() - 1 - i]) {
			return false;
		}
	}
	return true;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0); 

	string s; cin >> s;
	for (int i = 0; i < s.length(); i++) {
		dp[i] = INF;
	}

	for (int i = 0; i < s.length(); i++) {
		for (int j = i; j >= 0; j--) {
			string temp = s.substr(j, i - j + 1);
			if (check(temp)) {
				if (j == 0) {
					dp[i] = 1;
				}
				else {
					dp[i] = min(dp[i], dp[j - 1] + 1);
				}
			}
		}
	}
	cout << dp[s.length() - 1] << "\n";
}