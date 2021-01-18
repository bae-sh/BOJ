#include<iostream>
#include<string.h>
using namespace std;

int N;
int cur[10001];
int ob[10001];
int dp[10000][10];
int go(int depth,int p){//±Ì¿Ã ¥ı«œ±‚ 
	int cur_num = (cur[depth] + p) % 10;
	if (depth == N) {
		return 0;
	}
	if (dp[depth][p] != -1) {
		return dp[depth][p];
	}
	int l = (ob[depth] - cur_num + 10) % 10;
	int r = (cur_num - ob[depth] + 10) % 10;
	int left = go(depth + 1, (p + l) % 10) + l;
	int right = go(depth + 1, p) + r;
	if (left < right) {
		dp[depth][p] = left;
	}
	else {
		dp[depth][p] = right;
	}
	return dp[depth][p];
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	string c, o;
	cin >> N >> c >> o;
	for (int i = 0; i < N; i++) {
		cur[i] = c[i] - '0';
		ob[i] = o[i] - '0';
	}
	memset(dp, -1, sizeof(dp));
	cout << go(0, 0) << "\n";
}