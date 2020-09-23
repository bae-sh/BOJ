#include<stdio.h>
#include<algorithm>
using namespace std;
int N;
int d[1000000];
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &d[i]);
	}
	sort(d, d + N);
	for (int i = N - 1; i >= 2; i--) {
		if (d[i] < d[i - 1] + d[i - 2]) {
			printf("%d", d[i - 2] + d[i - 1] + d[i]);
			return 0;
		}
	}
	printf("-1");
}