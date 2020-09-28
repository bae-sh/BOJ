#include<stdio.h>
using namespace std;
int N,temp;
int ans = 1;
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &temp);
		ans += temp - 1;
	}
	printf("%d", ans);
}