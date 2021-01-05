#include<iostream>
#include<string>
using namespace std;
int dp[10000];
int n, m;
int possible;
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		int temp = 0;
		for (int j = 0; j < s.size(); j++) {
			int x = s[j] - 'a';
			temp |= (1 << x);
		}
		dp[i] = temp;
	}
	for (int i = 0; i < m; i++) {
		int ans = 0;
		int x; char y; cin >> x >> y;
		if (x == 1) {
			possible |= (1 << (y - 'a'));
		}
		else {
			possible &= ~(1 << (y - 'a'));
		}

		for (int j = 0; j < n; j++) {
			if ((dp[j] & possible) == 0) {
				ans++;
			}
		}
		cout << ans << "\n";
	}
}