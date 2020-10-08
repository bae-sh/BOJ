#include<stdio.h>
#include<vector>
using namespace std;
int N, M;
int num[2001];
int dp[2001][2001];

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &num[i]);
		dp[i][i] = 1;
		if (num[i - 1] == num[i]) {
			dp[i - 1][i] = 1;
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= 1000; j++) {//범위가 홀수일때
			int left = i - j;
			int right = i + j;
			if (1 <= left && right <= N) {
				if (dp[left + 1][right - 1] && num[left] == num[right]) {
					dp[left][right] = 1;
				}
			}
			left = i - j;//짝수일때
			right = i + 1 + j;
			if (1 <= left && right <= N) {
				if (dp[left + 1][right - 1] && num[left] == num[right]) {
					dp[left][right] = 1;
				}
			}
		}
	}
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		int S, E;
		scanf("%d %d", &S, &E);
		printf("%d\n", dp[S][E]);
	}
}