#include<stdio.h>
using namespace std;
long long S;
long long temp=1;
int main() {
	scanf("%d", &S);
	for (int i = 2;; i++) {
		temp += i;
		if (S<temp) {
			printf("%d", i - 1);
			break;
		}
	}
}