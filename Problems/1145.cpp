#include<stdio.h>
int A[5];
int main() {
	for (int i = 0; i < 5; i++) {
		scanf("%d", &A[i]);
	}
	for (int i = 1;; i++) {
		int cnt = 0;
		for (int j = 0; j < 5; j++) {
			if (i%A[j] == 0) {
				cnt++;
			}
		}
		if (cnt >= 3) {
			printf("%d", i);
			break;
		}
	}
}