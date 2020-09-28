#include<stdio.h>
using namespace std;
long long A, B;
long long k;
long long ans;
int main() {
	scanf("%lld %lld", &A, &B);
	if (A > B) {
		long long temp = A;
		A = B;
		B = temp;
	}
	k = B - A;
	if (k % 2 == 1) {
		ans = (A + B)*((k + 1) / 2);
		printf("%d", ans);
	}
	else {
		ans = (A + B)*(k / 2) + (A + B) / 2;
		printf("%d", ans);
	}
}