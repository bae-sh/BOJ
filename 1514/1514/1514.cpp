#include<iostream>
#include<string.h>
using namespace std;

int dp[101][11][11];
int N;
int a[101];
int b[101];
int turn[10] = { 0,1,1,1,2,2,2,1,1,1 };
int go(int i,int j,int k) {
	if (i == N) {
		return 0;
	}
	if (dp[i][j][k] != -1) {
		return dp[i][j][k];
	}
	int cur_num = (a[i] + j) % 10;
	for (int two = 0; two < 10; two++) {
		for (int three = 0; three < 10; three++) {
			int one = (b[i] - ((cur_num + three + two) % 10) +10) % 10;
			int cost = go(i + 1, (k + two + three) % 10, three) + turn[one] + turn[two] + turn[three];
			if (dp[i][j][k] == -1 || dp[i][j][k] > cost) {
				dp[i][j][k] = cost;
			}
		}
	}
	return dp[i][j][k];
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N;
	string s1, s2; cin >> s1 >> s2;

	for (int j = 0; j < s1.size(); j++) {
		a[j] = s1[j] - '0';
		b[j] = s2[j] - '0';
	}
	memset(dp, -1, sizeof(dp));

	cout << go(0, 0, 0) << "\n";
}