#include<stdio.h>
#include<algorithm>
using namespace std;
int N, M, x, y, K;
int map[20][20];
int dice[6];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int top = 1;
int moveDice[4][6] = { {1,5,2,3,0,4,},{4,0,2,3,5,1}, {2,1,5,0,4,3},{3,1,0,5,4,2} };
int tempDice[6];
int main() {
	scanf("%d %d %d %d %d", &N, &M, &x, &y, &K);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	for (int i = 0; i < K; i++) {
		int order;
		scanf("%d", &order);
		int nx = x + dx[order - 1];
		int ny = y + dy[order - 1];
		if (0 <= nx && nx < N && 0 <= ny && ny < M) {
			x = nx; y = ny;
			for (int i = 0; i < 6; i++) {
				tempDice[i] = dice[moveDice[order - 1][i]];
			}
			copy(tempDice, tempDice + 6, dice);
			if (map[nx][ny] == 0) {
				map[nx][ny] = dice[5];
			}
			else {
				dice[5] = map[nx][ny];
				map[nx][ny] = 0;
			}
			printf("%d\n", dice[0]);
		}
	}
}