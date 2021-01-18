#include<iostream>
#include<string.h>
using namespace std;

int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int r, c, t;
int map[50][50];
int next_map[50][50];
int air_x;
void way(int x) {
	for (int i = x + 1; i < r - 1; i++) {
		map[i][0] = map[i + 1][0];
	}
	for (int i = 1; i < c; i++) {
		map[r - 1][i - 1] = map[r - 1][i];
	}
	for (int i = r - 1; i > x; i--) {
		map[i][c - 1] = map[i - 1][c - 1];
	}
	for (int i = c - 1; i >= 1; i--) {
		if (i == 1) {
			map[x][i] = 0;
		}
		else {
			map[x][i] = map[x][i - 1];
		}
	}
}
void re_way(int x) {
	for (int i = x - 1; i > 0; i--) {
		map[i][0] = map[i - 1][0];
	}
	for (int i = 1; i < c; i++) {
		map[0][i - 1] = map[0][i];
	}
	for (int i = 0; i < x; i++) {
		map[i][c - 1] = map[i + 1][c - 1];
	}
	for (int i = c - 1; i > 0; i--) {
		if (i == 1) {
			map[x][i] = 0;
		}
		else {
			map[x][i] = map[x][i - 1];
		}
	}

}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> r >> c >> t;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
			if (map[i][j] == -1) {
				air_x = i;
			}
		}
	}
	while (t--) {
		memset(next_map, 0, sizeof(next_map));
		next_map[air_x - 1][0] = next_map[air_x][0] = -1;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (map[i][j] >= 1) {
					int cnt = 0;
					for (int k = 0; k < 4; k++) {
						int nx = i + dx[k];
						int ny = j + dy[k];
						if (0 <= nx && nx < r && 0 <= ny && ny < c && map[nx][ny] != -1) {
							next_map[nx][ny] += map[i][j] / 5;
							cnt++;
						}
					}
					next_map[i][j] += map[i][j] - (map[i][j] / 5) * cnt;
				}
			}
		}
		memcpy(map, next_map, sizeof(map));
		way(air_x);
		re_way(air_x - 1);
		int k = 2;
	}
	int ans = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] > 0) {
				ans += map[i][j];
			}
		}
	}
	cout << ans << "\n";
}