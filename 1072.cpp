#include<stdio.h>
#include<cmath>
using namespace std;
long long X,Y,Z;

int main() {
	scanf("%lli %lli", &X, &Y);
	if (99 * X - 100 * Y > 0) {
		long long temp = (Y * 100 / X) + 1;
		Z = ceil((temp*X-100*Y)*1.0/(100-temp));
	}
	else {
		Z = -1;
	}
	printf("%d", Z);
}