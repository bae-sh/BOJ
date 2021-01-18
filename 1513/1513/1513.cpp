#include<iostream>
#include<algorithm>
#include<string.h>
#define mod 1000007
using namespace std;
int dx[] = { 1,0 };
int dy[] = { 0,1 };
int N, M, C;
int dp[50][50][51][51];
int map[50][50];
long long ans;
int go(int x, int y, int game_num, int game_cnt) {
	if (game_cnt < 0) {
		return 0;
	}
	if (x == N - 1 && y == M - 1) {
		if (game_cnt == 0) {
			return 1;
		}
	}
	if (dp[x][y][game_num][game_cnt] != -1) {
		return dp[x][y][game_num][game_cnt];
	}
	dp[x][y][game_num][game_cnt] = 0;

	for (int i = 0; i < 2; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < N && 0 <= ny && ny < M) {
			if (map[nx][ny] != 0) {
				if (game_num < map[nx][ny] && game_cnt >0) {
					dp[x][y][game_num][game_cnt] += go(nx, ny, map[nx][ny], game_cnt - 1);
					dp[x][y][game_num][game_cnt] %= mod;
				}
			}
			else {
				dp[x][y][game_num][game_cnt] += go(nx, ny, game_num, game_cnt);
				dp[x][y][game_num][game_cnt] %= mod;
			}
		}
	}
	return dp[x][y][game_num][game_cnt];
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> M >> C;
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= C; i++) {
		int x, y; cin >> x >> y;
		map[x - 1][y - 1] = i;
	}
	for (int i = 0; i <= C; i++) {
		if (map[0][0] != 0) {
			cout << go(0, 0, map[0][0], i - 1) << " ";
		}
		else {
			cout << go(0, 0, map[0][0], i) << " ";
		}
	}
}