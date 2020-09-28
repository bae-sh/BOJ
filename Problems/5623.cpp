#include<stdio.h>
int N;
int S[1000][1000];
int A[1000];
int sum;
int part_sum;
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &S[i][j]);
		}
	}
	if (N == 2) {
		printf("1 1");
	}
	else {
		for (int i = 0; i < N - 1; i++) {
			sum += S[i][i + 1];
		}
		sum += S[N - 1][0];
		sum /= 2;
		for (int i = 1; i < N - 1; i++) {
			part_sum += S[i][i + 1];
		}
		part_sum += S[N - 1][1];
		part_sum /= 2;
		A[0] = sum - part_sum;
		for (int i = 1; i < N; i++) {
			A[i] = S[i - 1][i] - A[i - 1];
		}
		for (int i = 0; i < N; i++) {
			printf("%d ", A[i]);
		}
	}
}