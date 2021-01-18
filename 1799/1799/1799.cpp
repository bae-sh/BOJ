#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int map[10][10];
int map_color[10][10];//black Àº 1 white ´Â 0
int n;
int dx[] = { -1,-1 };
int dy[] = { -1,1 };
int dfs(int pos, int cnt, int color) {
	int ans = 0;
	int x = pos / n;
	int y = pos % n;
	if (pos >= n * n) {
		return cnt;
	}
	if (map[x][y] == 0 || map_color[x][y] != color) {
		return dfs(pos + 1, cnt, color);
	}
	else {
		bool possible = true;
		for (int i = 0; i < 2; i++) {
			if (!possible) break;
			for (int j = 1;; j++) {
				int nx = x + dx[i] * j;
				int ny = y + dy[i] * j;
				if (0 <= nx && nx < n && 0 <= ny && ny < n) {
					if (map[nx][ny] == 2) {
						possible = false;
						break;
					}
				}
				else {
					break;
				}
			}
		}

		if (possible) {
			map[x][y] = 2;
			ans = max(ans, dfs(pos + 1, cnt + 1, color));
			map[x][y] = 1;
		}
		ans = max(ans, dfs(pos + 1, cnt, color));
		return ans;
	}
	
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;
	int color = 0;
	for (int i = 0; i < n; i++) {
		color = (1 - color);
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (j % 2 == 0) {
				map_color[i][j] = color;
			}
			else {
				map_color[i][j] = (1 - color);
			}
		}
	}
	cout << dfs(0, 0, 0) + dfs(0, 0, 1) << "\n";
}