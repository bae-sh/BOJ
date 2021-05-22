#include<iostream>
#include<algorithm>
#include<queue>
#include<string.h>
#include<vector>
using namespace std;
int map[50][50];//B>2 E>3
int dp[50][50][2];//중심점을 기준으로 세로 가로
int n, sx, sy, sway, ex, ey, eway, scnt, ecnt, ans; // 가로 1 세로 0
int dx[] = { -1,0,1,0,-1,-1,1,1 };
int dy[] = { 0,1,0,-1,-1,1,1,-1 };
vector<pair<int, int>> st;
vector<pair<int, int>> e;
bool moveU(int x, int y,int way) {
	int nx = x + dx[0];
	int ny = y + dy[0];
	if (way == 0) {//세로
		nx--;//맨위
		if (0 <= nx && nx < n && 0 <= ny && ny < n) {
			if (map[nx][ny] != 1) {
				nx++;//중심점
				if (dp[nx][ny][way] == -1) {
					dp[nx][ny][way] = dp[x][y][way] + 1;
					return true;
				}
			}
		}
	}
	else {
		if (0 <= nx && nx < n && 0 <= ny && ny < n) {
			if (map[nx][ny - 1] != 1 && map[nx][ny] != 1 && map[nx][ny + 1] != 1) {
				if (dp[nx][ny][way] == -1) {
					dp[nx][ny][way] = dp[x][y][way] + 1;
					return true;
				}
			}
		}
	}
	return false;
}
bool moveD(int x, int y, int way) {
	int nx = x + dx[2];
	int ny = y + dy[2];
	if (way == 0) {//세로
		nx++;//맨위
		if (0 <= nx && nx < n && 0 <= ny && ny < n) {
			if (map[nx][ny] != 1) {
				nx--;//중심점
				if (dp[nx][ny][way] == -1) {
					dp[nx][ny][way] = dp[x][y][way] + 1;
					return true;
				}
			}
		}
	}
	else {
		if (0 <= nx && nx < n && 0 <= ny && ny < n) {
			if (map[nx][ny - 1] != 1 && map[nx][ny] != 1 && map[nx][ny + 1] != 1) {
				if (dp[nx][ny][way] == -1) {
					dp[nx][ny][way] = dp[x][y][way] + 1;
					return true;
				}
			}
		}
	}
	return false;
}

bool moveL(int x, int y, int way) {
	int nx = x + dx[3];
	int ny = y + dy[3];
	if (way == 0) {//세로
		if (0 <= nx && nx < n && 0 <= ny && ny < n) {
			if (map[nx - 1][ny] != 1 && map[nx][ny] != 1 && map[nx + 1][ny] != 1) {
				if (dp[nx][ny][way] == -1) {
					dp[nx][ny][way] = dp[x][y][way] + 1;
					return true;
				}
			}
		}
	}
	else {
		ny--;//왼쪽
		if (0 <= nx && nx < n && 0 <= ny && ny < n) {
			if (map[nx][ny] != 1) {
				ny++;//중심점
				if (dp[nx][ny][way] == -1) {
					dp[nx][ny][way] = dp[x][y][way] + 1;
					return true;
				}
			}
		}
	}
	return false;
}

bool moveR(int x, int y, int way) {
	int nx = x + dx[1];
	int ny = y + dy[1];
	if (way == 0) {//세로
		if (0 <= nx && nx < n && 0 <= ny && ny < n) {
			if (map[nx - 1][ny] != 1 && map[nx][ny] != 1 && map[nx + 1][ny] != 1) {
				if (dp[nx][ny][way] == -1) {
					dp[nx][ny][way] = dp[x][y][way] + 1;
					return true;
				}
			}
		}
	}
	else {
		ny++;//왼쪽
		if (0 <= nx && nx < n && 0 <= ny && ny < n) {
			if (map[nx][ny] != 1) {
				ny--;//중심점
				if (dp[nx][ny][way] == -1) {
					dp[nx][ny][way] = dp[x][y][way] + 1;
					return true;
				}
			}
		}
	}
	return false;
}

bool moveT(int x, int y, int way) {
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < n && 0 <= ny && ny < n) {
			if (map[nx][ny] == 1) return false;
		}
		else return false;
	}
	if (dp[x][y][way ^ 1] == -1) {
		dp[x][y][way ^ 1] = dp[x][y][way] + 1;
		return true;
	}
	return false;
}
void bfs() {
	queue<pair<pair<int, int>,int>> q;
	q.push({ { sx,sy },sway });
	dp[sx][sy][sway] = 0;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int way = q.front().second; q.pop();
		if (ex == x && ey == y && eway == way)break;
		if (moveU(x, y, way)) q.push({ {x - 1,y},way });
		if (moveD(x, y, way)) q.push({ {x + 1,y},way });
		if (moveL(x, y, way)) q.push({ {x,y - 1},way });
		if (moveR(x, y, way)) q.push({ {x,y + 1},way });
		if (moveT(x, y, way)) q.push({ {x,y},way ^ 1 });
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < n; j++) {
			if (s[j] == 'B') {
				st.push_back({ i,j });
			}
			else if (s[j] == 'E') {
				e.push_back({ i,j });
			}
			else {
				map[i][j] = s[j] - '0';
			}
		}
	}
	sx = st[1].first; sy = st[1].second; ex = e[1].first; ey = e[1].second;
	sway = st[0].first == st[1].first;
	eway = e[0].first == e[1].first;
	memset(dp, -1, sizeof(dp));
	bfs();
	if (dp[ex][ey][eway] == -1) {
		cout << "0" << "\n";
	}
	else {
		cout << dp[ex][ey][eway] << "\n";
	}
}