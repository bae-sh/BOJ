#include<stdio.h>
#include<algorithm>
using namespace std;
int N, M;
int T[500][500];
int dp[500][500];
int dx[] = { 0,-1,0,1 };
int dy[] = { -1,0,1,0 };
int Max;
void search(int x, int y,int result,int deep) {
	result += T[x][y];
	if (deep == 4) {
		Max = max(Max, result);
		return;
	}
	else {
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < N && 0 <= ny && ny < M && !dp[nx][ny]) {
				if (deep == 2) {//ㅗ모양 예외처리
					int kx = x + dx[(i + 1) % 4];
					int ky = y + dy[(i + 1) % 4];
					if (0 <= kx && kx < N && 0 <= ky && ky < M && !dp[kx][ky]) {
						Max = max(Max, result + T[nx][ny] + T[kx][ky]);
					}
				}
				dp[nx][ny] = 1;
				search(nx, ny, result, deep + 1);
				dp[nx][ny] = 0;
			}
		}
	}
}
int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &T[i][j]);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			dp[i][j] = 1;
			search(i, j, 0, 1);
			dp[i][j] = 0;
		}
	}
	printf("%d", Max);
}