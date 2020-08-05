#include<stdio.h>
using namespace std;
int N;
int Candy[999];
int CandyPlus[999];
int all;
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &CandyPlus[i]);
		all += CandyPlus[i];
	}
	all /= 2;
	for (int i = 0; i < N-1; i += 2) {
		all -= CandyPlus[i];
	}
	Candy[N - 1] = all;

	for (int i = N - 2; i >= 0; i--) {
		Candy[i] = CandyPlus[i] - Candy[i + 1];
	}

	for (int i = 0; i < N; i++) {
		printf("%d\n", Candy[i]);
	}
}