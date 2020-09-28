#include<stdio.h>
#include<queue>
#include<tuple>
using namespace std;
int N, M, ans;
int Room[50][50];//ºóÄ­ 0 º® 1 Ã»¼Ò¿Ï·á 2
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
void dfs(int x,int y,int d) {
	Room[x][y] = 2;
	int way = 0;
	for (int i = 0; i < 4; i++) {
		way = (d + 3) % 4;
		int nx = x + dx[way];
		int ny = y + dy[way];
		if (0 <= nx && nx < N && 0 <= ny && ny < M) {
			if (Room[nx][ny] == 0) {
				return dfs(nx, ny, way);
			}
		}
		d =(d+ 3)%4;
	}
	way = (d + 6) % 4;
	int nx = x + dx[way];
	int ny = y + dy[way];
	if (Room[nx][ny] == 1) {
		return;
	}
	else {
		return dfs(nx, ny, d);
	}
}
int main() {
	int r, c, d;
	scanf("%d %d", &N, &M);
	scanf("%d %d %d", &r, &c, &d);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &Room[i][j]);
		}
	}
	dfs(r, c, d);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (Room[i][j] == 2) {
				ans++;
			}
		}
	}
	printf("%d", ans);
}