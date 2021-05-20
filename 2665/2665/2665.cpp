#include<iostream>
#include<algorithm>
#include<string.h>
#include<queue>
using namespace std;
int n;
int map[50][50];// 0>black 1>white
int dp[50][50];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
void bfs() {
	queue<pair<int, int>> q;
	q.push({ 0,0 });
	dp[0][0] = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second; q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				int black = map[nx][ny] ^ 1;
				if (dp[nx][ny] == -1 || dp[nx][ny] > dp[x][y] + black) {
					dp[nx][ny] = dp[x][y] + black;
					q.push({ nx,ny });
				}
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < s.size(); j++) {
			map[i][j] = s[j] - '0';
			dp[i][j] = -1;
		}
	}
	bfs();
	cout << dp[n - 1][n - 1] << "\n";
}