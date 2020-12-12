#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<tuple>
#include<string.h>
using namespace std;
int N;
int map[10][10];
int dp[10][10][3][101];//x,y,what,current_positon
int dx1[] = { -1,0,1,0 };
int dy1[] = { 0,1,0,-1 };//·è
int dx2[] = { -1,1,1,-1 };
int dy2[] = { 1,1,-1,-1 };//ºñ¼ó
int dx3[] = { -2,-1,1,2,2,1,-1,-2 };
int dy3[] = { 1,2,2,1,-1,-2,-2,-1 };//³ªÀÌÆ®
queue<tuple<int, int, int, int>> q;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N;
	memset(dp, -1, sizeof(dp));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int x; cin >> x;
			map[i][j] = x;
			if (x == 1) {
				for (int k = 0; k < 3; k++) {
					q.push({ i,j,k,1 });
					dp[i][j][k][1] = 0;
				}
			}
		}
	}
	int ans = -1;
	while (!q.empty()) {
		int x, y, way, pos;
		tie(x, y, way, pos) = q.front(); q.pop();
		if (pos == N * N) {
			cout << dp[x][y][way][pos];
			return 0;
		}
		if (way == 0) {
			for (int i = 0; i < 4; i++) {
				for (int l = 1;; l++) {
					int nx = x + dx1[i] * l;
					int ny = y + dy1[i] * l;
					int npos = pos;
					if (0 <= nx && nx < N && 0 <= ny && ny < N) {
						if (map[nx][ny] == pos + 1) {
							npos++;
						}
						if (dp[nx][ny][way][npos] == -1) {
							dp[nx][ny][way][npos] = dp[x][y][way][pos] + 1;
							q.push({ nx,ny,way,npos });
						}
					}
					else {
						break;
					}
				}
			}
			
		}
		else if (way == 1) {
			for (int i = 0; i < 4; i++) {
				for (int l = 1;; l++) {
					int nx = x + dx2[i] * l;
					int ny = y + dy2[i] * l;
					int npos = pos;
					if (0 <= nx && nx < N && 0 <= ny && ny < N) {
						if (map[nx][ny] == pos + 1) {
							npos++;
						}
						if (dp[nx][ny][way][npos] == -1) {
							dp[nx][ny][way][npos] = dp[x][y][way][pos] + 1;
							q.push({ nx,ny,way,npos });
						}
					}
					else {
						break;
					}
				}
			}
		}
		else if (way == 2) {
			for (int i = 0; i < 8; i++) {
				int nx = x + dx3[i];
				int ny = y + dy3[i];
				int npos = pos;
				if (0 <= nx && nx < N && 0 <= ny && ny < N) {
					if (map[nx][ny] == pos + 1) {
						npos++;
					}
					if (dp[nx][ny][way][npos] == -1) {
						dp[nx][ny][way][npos] = dp[x][y][way][pos] + 1;
						q.push({ nx,ny,way,npos });
					}
				}
			}
		}

		for (int i = 1; i < 3; i++) {
			if (dp[x][y][(way + i) % 3][pos] == -1) {
				dp[x][y][(way + i) % 3][pos] = dp[x][y][way][pos] + 1;
				q.push({ x,y,(way + i) % 3,pos });
			}
		}
	}
}