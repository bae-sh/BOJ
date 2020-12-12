#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<tuple>
#include<string.h>
using namespace std;
int N;
int map[10][10];
pair<int,int> dp[10][10][3][101];//x,y,what,current_positon
int dx1[] = { -1,0,1,0 };
int dy1[] = { 0,1,0,-1 };//·è
int dx2[] = { -1,1,1,-1 };
int dy2[] = { 1,1,-1,-1 };//ºñ¼ó
int dx3[] = { -2,-1,1,2,2,1,-1,-2 };
int dy3[] = { 1,2,2,1,-1,-2,-2,-1 };//³ªÀÌÆ®
queue<tuple<int, int, int, int>> q;
pair<int, int> ans = { -1,-1 };
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
					dp[i][j][k][1] = { 0,0 };
				}
			}
		}
	}

	while (!q.empty()) {
		int x, y, way, pos;
		tie(x, y, way, pos) = q.front(); q.pop();
		auto& p = dp[x][y][way][pos];
		if (pos == N * N) {
			if (ans.first == -1 || ans > p) {
				ans = p;
			}
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
						if (dp[nx][ny][way][npos].first == -1) {
							dp[nx][ny][way][npos].first = dp[x][y][way][pos].first + 1;
							dp[nx][ny][way][npos].second = dp[x][y][way][pos].second;
							q.push({ nx,ny,way,npos });
						}
						else if (dp[nx][ny][way][npos].first >= dp[x][y][way][pos].first + 1) {
							if (dp[nx][ny][way][npos].second > dp[x][y][way][pos].second) {
								dp[nx][ny][way][npos].first = dp[x][y][way][pos].first + 1;
								dp[nx][ny][way][npos].second = dp[x][y][way][pos].second;
								q.push({ nx,ny,way,npos });
							}
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
						if (dp[nx][ny][way][npos].first == -1) {
							dp[nx][ny][way][npos].first = dp[x][y][way][pos].first + 1;
							dp[nx][ny][way][npos].second = dp[x][y][way][pos].second;
							q.push({ nx,ny,way,npos });
						}
						else if (dp[nx][ny][way][npos].first >= dp[x][y][way][pos].first + 1) {
							if (dp[nx][ny][way][npos].second > dp[x][y][way][pos].second) {
								dp[nx][ny][way][npos].first = dp[x][y][way][pos].first + 1;
								dp[nx][ny][way][npos].second = dp[x][y][way][pos].second;
								q.push({ nx,ny,way,npos });
							}
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
					if (dp[nx][ny][way][npos].first == -1) {
						dp[nx][ny][way][npos].first = dp[x][y][way][pos].first + 1;
						dp[nx][ny][way][npos].second = dp[x][y][way][pos].second;
						q.push({ nx,ny,way,npos });
					}
					else if (dp[nx][ny][way][npos].first >= dp[x][y][way][pos].first + 1) {
						if (dp[nx][ny][way][npos].second > dp[x][y][way][pos].second) {
							dp[nx][ny][way][npos].first = dp[x][y][way][pos].first + 1;
							dp[nx][ny][way][npos].second = dp[x][y][way][pos].second;
							q.push({ nx,ny,way,npos });
						}
					}
				}
			}
		}

		for (int i = 0; i < 3; i++) {
			if (way == i) continue;
			auto np = make_pair(p.first + 1, p.second + 1);
			if (dp[x][y][i][pos].first == -1 || dp[x][y][i][pos] > np) {
				dp[x][y][i][pos] = np;
				q.push(make_tuple(x, y, i, pos));
			}
		}
	}
	cout << ans.first<< " " << ans.second;
}