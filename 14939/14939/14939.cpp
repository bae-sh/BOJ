#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int map[10][10];
int ans = -1;
int dx[] = { -1,0,1,0,0 };
int dy[] = { 0,1,0,-1,0 };
void dfs(int y,int cnt) {
	int temp[10][10];
	memcpy(temp, map, sizeof(temp));
	if (y == 10) {
		for (int i = 1; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (temp[i - 1][j] == 1) {
					for (int k = 0; k < 5; k++) {
						int nx = i + dx[k];
						int ny = j + dy[k];
						if (0 <= nx && nx < 10 && 0 <= ny && ny < 10) {
							temp[nx][ny] ^= 1;
						}
					}
					cnt++;
				}
			}
		}
		bool all = true;
		for (int i = 0; i < 10; i++) {
			if (temp[9][i] == 1) {
				all = false;
				break;
			}
		}
		if (all) {
			if (ans == -1) {
				ans = cnt;
			}
			else {
				ans = min(ans, cnt);
			}
		}
	}
	else {
		dfs(y + 1, cnt);
		for (int k = 0; k < 5; k++) {
			int nx = 0 + dx[k];
			int ny = y + dy[k];
			if (0 <= nx && nx < 10 && 0 <= ny && ny < 10) {
				map[nx][ny] ^= 1;
			}
		}
		dfs(y + 1, cnt + 1);
		for (int k = 0; k < 5; k++) {
			int nx = 0 + dx[k];
			int ny = y + dy[k];
			if (0 <= nx && nx < 10 && 0 <= ny && ny < 10) {
				map[nx][ny] ^= 1;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			char c; cin >> c;
			map[i][j] = (c == '#') ? 0 : 1;
		}
	}
	dfs(0, 0);
	cout << ans << "\n";
}