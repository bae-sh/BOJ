#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<tuple>
#define INF 987654321
using namespace std;

int N, M;
int map[1000][1000];
vector <pair<int, int>> wall;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

int bfs() {
	int dp[1000][1000][2] = { 0 };//x,y,º®À» ¶ÕÀº È½¼ö
	dp[N - 1][M - 1][0] = INF;
	dp[N - 1][M - 1][1] = INF;
	dp[0][0][0] = 1;
	queue<tuple<int, int, int>> q;
	q.push(make_tuple(0, 0, 0));//x,y,º®À»¶ÕÀºÈ½¼ö
	while (!q.empty()) {
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		int jump = get<2>(q.front());
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < N && 0 <= ny && ny < M) {
				if (map[nx][ny] == 0) {
					if (dp[nx][ny][jump] == 0 || dp[nx][ny][jump] > dp[x][y][jump] + 1) {
						dp[nx][ny][jump] = dp[x][y][jump] + 1;
						q.push(make_tuple(nx, ny, jump));
					}
				}
				else if (map[nx][ny] == 1 && jump == 0) {
					if (dp[nx][ny][jump + 1] == 0 || dp[nx][ny][jump + 1] > dp[x][y][jump] + 1) {
						dp[nx][ny][jump + 1] = dp[x][y][jump] + 1;
						q.push(make_tuple(nx, ny, jump + 1));
					}
				}
			}
		}
	}

	return min(dp[N - 1][M - 1][0], dp[N - 1][M - 1][1]);
}
int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		char c[1020];
		scanf("%s", c);
		for (int j = 0; j < M; j++) {
			map[i][j] = c[j] - '0';
		}
	}
	int ans = bfs();
	if (ans == INF) {
		printf("-1");
	}
	else {
		printf("%d", ans);
	}
}