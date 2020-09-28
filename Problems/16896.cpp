#include<stdio.h>
using namespace std;
int T;
int main() {
	scanf("%d", &T);
	while (T-- > 0) {
		long long N;
		scanf("%lld", &N);
		long long k = N;
		if (N % 2 == 0) {
			printf("cubelover\n");
		}
		else {
			int p = 1;//1:Â¦o 2:¸ÕÀúx 3:È¦ o
			while (1) {
				if (N == 2 || N == 3) {
					if (p == 1) {
						printf("koosaga\n");
					}
					else if (p == 2) {
						printf("cubelover\n");
					}
					else if (p == 3) {
						printf("cubelover\n");
					}
					break;
				}
				if(N%2!=0) N--;
				N = N / 2;
				if (p == 1) {
					p = 2;
				}
				else if (p == 2) {
					if (N % 2 == 0) {
						p = 1;
					}
					else {
						p = 3;
					}
				}
			}
		}
	}
}