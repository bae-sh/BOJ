#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<string.h>
using namespace std;
int N, M;
int map[1001][1001];
int dp[1001][1001];
int cnt[1001][1001];
int H, W, Sr, Sc, Fr, Fc;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			int t; cin >> t;
			map[i][j] = t;
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] - map[i][j] + 1;
		}
	}
	cin >> H >> W >> Sr >> Sc >> Fr >> Fc;
	int area = H * W;
	queue<pair<int, int>> q;
	q.push({ Sr,Sc });
	memset(cnt, -1, sizeof(cnt));
	cnt[Sr][Sc] = 0;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second; q.pop();

		if (x == Fr && y == Fc) {
			cout << cnt[x][y] << "\n";
			return 0;
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx + H - 1 <= N && 0 <= ny && ny + W - 1 <= M && cnt[nx][ny] == -1) {
				if (area == dp[nx + H - 1][ny + W - 1] - dp[nx - 1][ny + W - 1] - dp[nx + H - 1][ny - 1] + dp[nx - 1][ny - 1]) {
					q.push({ nx, ny});
					cnt[nx][ny] = cnt[x][y] + 1;
				}
			}
		}
	}
	cout << -1 << "\n";
}