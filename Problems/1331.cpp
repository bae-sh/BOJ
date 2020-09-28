#include<stdio.h>
using namespace std;
int dp[6][6];
int x[37];//행
int y[37];//열
const int nx[] = { 2,1,-1,-2,-2,-1,1,2 };
const int ny[] = { 1,2,2,1,-1,-2,-2,-1 };
bool ans=true;

bool go(int i) {//말이 움직일수 있는 가 판별 함수
	for (int j = 0; j < 8; j++) {
		if (x[i - 1] + nx[j] == x[i] && y[i - 1] + ny[j] == y[i]) {
			if (dp[x[i]][y[i]] == 0) {
				dp[x[i]][y[i]] = 1;
				return ans;
			}
		}
	}
	return false;
}

int main() {
	char str[10];
	for (int i = 0; i < 36; i++) {
		scanf("%s", str);
		x[i] = str[1] - '1';
		y[i] = str[0] - 'A';
		if (0 <= x[i], y[i] < 6) {
			if (i == 0) {
				dp[x[i]][y[i]] = 1;
			}
			else {
				ans = go(i);
			}
		}
		else {
			ans = false;
		}
	}

	x[36] = x[0]; y[36] = y[0];
	dp[x[0]][y[0]] = 0;//처음값 초기화
	ans = go(36);

	if (ans) {
		printf("Valid");
	}else{
		printf("Invalid");
	}
	return 0;
}