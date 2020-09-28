#include<stdio.h>
using namespace std;
int N;
int num[100];
long long dp[100][21];
long long ans;

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num[i]);
	}
	dp[0][num[0]] = 1;
	for (int i = 1; i < N - 1; i++) {
		for (int j = 0; j < 21; j++) {
			if (dp[i - 1][j] != 0) {
				int temp = j + num[i];
				if (0 <= temp && temp < 21) {
					dp[i][temp] += dp[i - 1][j];
				}
				temp = j - num[i];

				if (0 <= temp && temp < 21) {
					dp[i][temp] += dp[i - 1][j];
				}
			}
		}
	}
	printf("%lld", dp[N - 2][num[N - 1]]);
}