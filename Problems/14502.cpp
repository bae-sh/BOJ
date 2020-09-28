#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int N, M;
int Map[8][8];
int dp[8][8];
int ans;
void copy() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			dp[i][j] = Map[i][j];
		}
	}
}
void virus() {
	int A = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (dp[i][j] == 0) {
				A++;
			}
		}
	}
	ans = max(ans, A);
}
void bfs() {
	queue<pair<int, int>> q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (dp[i][j] == 2) {
				q.push(make_pair(i, j));
			}
		}
	}
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < N && 0 <= ny && ny < M) {
				if (dp[nx][ny] == 0) {
					dp[nx][ny] = 2;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	virus();
}
void serching_wall(int num) {
	bool tf = false;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (dp[i][j] == num) {
				tf = true;
			}
			else if (dp[i][j] == 0 && tf) {
				if (num == -1) {
					Map[i][j] = -2;
					copy();
					serching_wall(num - 1);
					Map[i][j] = 0;
				}
				else {
					dp[i][j] = -3;
					bfs();
					Map[i][j] = 0;
					copy();
				}
			}
		}
	}
}
int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &Map[i][j]);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (Map[i][j] == 0) {
				Map[i][j] = -1;
				copy();
				serching_wall(-1);
				Map[i][j] = 0;
			}
		}
	}
	printf("%d", ans);
}