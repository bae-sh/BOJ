#include<iostream>
#include<cstring>
#include<algorithm>
#define INF 987654321
using namespace std;
long long dp[2501];
int pal[2501][2501];
string s;
int check(int start, int end) {
	if (start >= end) {
		return 1;
	}
	if (pal[start][end] != -1) {
		return pal[start][end];
	}
	if (s[start] != s[end]) {
		return pal[start][end] = 0;
	}
	return pal[start][end] = check(start + 1, end - 1);
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0); 

	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		dp[i] = INF;
	}
	memset(pal, -1, sizeof(pal));
	for (int i = 0; i < s.length(); i++) {
		for (int j = 0; j <= i; j++) {
			if (check(j,i)) {
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