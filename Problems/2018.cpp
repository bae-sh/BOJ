#include<stdio.h>
using namespace std;
int N;
int cnt;
int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		if (i % 2 != 0) {//È¦¼ö
			if (N%i == 0 && N / i - i / 2 > 0) {
				cnt++;
			}
		}
		else {//Â¦¼ö
			if (N%i == i / 2 && N / i - i / 2 >= 0) {
				cnt++;
			}
		}
	}
	printf("%d", cnt);
}