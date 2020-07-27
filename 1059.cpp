#include<stdio.h>
#include<algorithm>
using namespace std;
int n;//LÀÇ °³¼ö
int L[1000];
int N;
int ans;

int main() {
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &L[i]);
	}
	sort(L, L + n);
	scanf("%d", &N);

	if (N < L[0]) {
		printf("%d", N*(L[0] - N) - 1);
	}
	else {
		for (int i = 0; i < n - 1; i++) {
			if (L[i] < N && N < L[i + 1]) {
				ans = (N - L[i])*(L[i + 1] - N) - 1;
				break;
			}
		}
		printf("%d", ans);
	}
}