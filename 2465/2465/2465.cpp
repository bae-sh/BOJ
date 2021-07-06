#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string.h>
#include<stack>
#define MAX 987654321
using namespace std;

int n, k, t;
int map[51][51];
int dp[51][51];
int sx, sy, ex, ey;

int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0, -1 };
pair<int, int> trace[51][51];
stack<pair<int, int>> st;
int find_way(int x, int y, int nx, int ny) {
	if (x == nx) {
		if (y - ny > 0) {
			return 3;
		}
		else {
			return 1;
		}
	}
	else {
		if (x - nx > 0) {
			return 0;
		}
		else {
			return 2;
		}
	}
}
void bfs() {
	queue<pair<int, int>> q;
	q.push({ sx,sy });
	dp[sx][sy] = map[sx][sy];
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second; q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (1 <= nx && nx <= n && 1 <= ny && ny <= n) {
				if (dp[nx][ny] > dp[x][y] + map[nx][ny]) {
					dp[nx][ny] = dp[x][y] + map[nx][ny];
					trace[nx][ny] = { x,y };
					if (x == ex && y == ey) {
						continue;
					}
					q.push({ nx,ny });
				}
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;
	cin >> sx >> sy >> ex >> ey;
	cin >> k >> t;

	for (int i = 0; i < 51; i++) {
		for (int j = 0; j < 51; j++) {
			map[i][j] = 1;
			dp[i][j] = MAX;
		}
	}

	while (t--) {
		int m; cin >> m;
		int x, y; cin >> x >> y;

		while (m-- > 1) {
			int nx, ny; cin >> nx >> ny;
			int way = find_way(x, y, nx, ny);

			while (true) {
				map[x][y] = k;
				if (x == nx && y == ny) break;
				x = x + dx[way]; y = y + dy[way];
			}
		}
	}
	bfs();

	int x = ex;
	int y = ey;
	int way = -1;

	while (true) {
		int pre_x = trace[x][y].first;
		int pre_y = trace[x][y].second;
		if (pre_x == 0 && pre_y == 0) {
			st.push({ x,y });
			break;
		}
		int nway = find_way(pre_x, pre_y, x, y);
		if (way != nway) {
			way = nway;
			st.push({ x,y });
		}
		x = pre_x; y = pre_y;
	}

	cout << dp[ex][ey] << "\n" << st.size() << " ";
	while (!st.empty()) {
		x = st.top().first;
		y = st.top().second; st.pop();
		cout << x << " " << y << " ";
	}
}