#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
long long dp[11][101][101][101];//level,red ,green, blue
long long c[11][11];
long long go(int level, int r, int g, int b) {
	if (r < 0 || g < 0 || b < 0 ) return 0;
	if (level == 0) return 1;
	if (dp[level][r][g][b] != -1) {
		return dp[level][r][g][b];
	}
	dp[level][r][g][b] = 0;
	dp[level][r][g][b] += go(level - 1, r - level, g, b) + go(level - 1, r, g - level, b) + go(level - 1, r, g, b - level);
	if (level % 2 == 0) {
		long long temp= go(level - 1, r - level / 2, g - level / 2, b) + go(level - 1, r - level / 2, g, b - level / 2) + go(level - 1, r , g - level / 2, b - level / 2);
		dp[level][r][g][b] += temp * c[level][level / 2];
	}
	if (level % 3 == 0) {
		long long temp= go(level - 1, r - (level / 3), g - (level / 3), b - (level / 3));
		dp[level][r][g][b] += temp * c[level][level / 3] * c[level - (level / 3)][level / 3];
	}
	return dp[level][r][g][b];

}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int N, r, g, b;
	cin >> N >> r >> g >> b;
	c[0][0] = 1;
	for (int i = 1; i <= 10; i++) {
		c[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
		}
	}
	memset(dp, -1, sizeof(dp));
	go(N, r, g, b);
	cout << dp[N][r][g][b] << "\n";
}