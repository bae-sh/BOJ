#include<stdio.h>
#include<queue>
using namespace std;
int N;
char Color[100][100];//123
int Person[100][100][2];//0번은 정상 1번은 적록색약
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int bfs(int num) {
	int Max = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (Person[i][j][num] == 0) {
				char c = Color[i][j];
				//printf("%d %d\n", i, j);
				Max++;
				queue<pair<int, int>> q;
				q.push(make_pair(i, j));
				Person[i][j][num] = Max;
				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					for (int k = 0; k < 4; k++) {
						int nx = x + dx[k];
						int ny = y + dy[k];
						if (0 <= nx && nx < N && 0 <= ny && ny < N) {
							if (Color[nx][ny] == c && Person[nx][ny][num] == 0) {
								q.push(make_pair(nx, ny));
								Person[nx][ny][num] = Max;
							}
							else if (((c == 'R') || (c == 'G')) && ((Color[nx][ny] == 'R') || (Color[nx][ny] == 'G')) && num == 1) {
								if (Person[nx][ny][num] == 0) {
									q.push(make_pair(nx, ny));
									Person[nx][ny][num] = Max;
								}
							}
						}
					}
				}
			}
		}
	}
	return Max;
}
int main() {
	scanf("%d\n", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf(" %c", &Color[i][j]);
		}
		scanf("");
	}
	printf("%d %d", bfs(0), bfs(1));
}