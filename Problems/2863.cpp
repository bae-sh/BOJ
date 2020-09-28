#include<stdio.h>
using namespace std;
int K[4];
double MAX;
int ans;
int main() {
	scanf("%d %d", &K[0], &K[1]);
	scanf("%d %d", &K[3], &K[2]);
	for (int i = 0; i < 4; i++) {
		double X = K[(4 - i) % 4] * 1.0 / K[(7 - i) % 4] ;
		double Y = K[(5 - i) % 4] * 1.0 / K[(6 - i) % 4] ;
		if (MAX < X + Y) {
			MAX = X + Y;
			ans = i;
		}
	}
	printf("%d", ans);
}