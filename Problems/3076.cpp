#include<stdio.h>
using namespace std;
int R, C, A, B;
bool wht;
char dp[100][100];
void color(int a, int b, int x, int y) {
	for (int i = x; i < x + a; i++) {
		for (int j = y; j < y + b; j++) {
			dp[i][j] = wht ? '.' : 'X';
		}
	}
	wht = !wht;
}
int main(){
	scanf("%d %d %d %d",&R,&C,&A,&B) ;
	for (int i = 0; i < R*A; i += A) {
		wht = (i / A) % 2 ;
		for (int j = 0; j < C*B; j += B) {
			color(A, B, i, j);
		}
	}
	for (int i = 0; i < R*A; i++) {
		for (int j = 0; j < C*B; j++) {
			printf("%c", dp[i][j]);
		}
		printf("\n");
	}
}