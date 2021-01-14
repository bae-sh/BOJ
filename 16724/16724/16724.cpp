#include<iostream>
#include<algorithm>
using namespace std;
int map[1000][1000];
int check[1000][1000];
int N, M;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int ans = 1;
int dfs(int x, int y) {
	check[x][y] = ans;
	int i = map[x][y];
	int nx = x + dx[i];
	int ny = y + dy[i];
	if (check[nx][ny] != 0) {
		if (check[nx][ny] == ans) {
			ans++;
		}
		return check[x][y] = check[nx][ny];
	}
	return check[x][y] = dfs(nx, ny);
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char c; cin >> c;
			if (c == 'U') {
				map[i][j] = 0;
			}
			else if (c == 'R') {
				map[i][j] = 1;
			}
			else if (c == 'D') {
				map[i][j] = 2;
			}
			else {
				map[i][j] = 3;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (check[i][j] == 0) {
				dfs(i, j);
			}
		}
	}
	cout << ans - 1 << "\n";
}