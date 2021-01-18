#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
using namespace std;
string N;
int num;
int len;
long long dp[10][10];//자리수에  한숫자가 나올수 있는 경우의수
long long a[10];
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	for (int i = 1; i <= 9; i++) {
		dp[1][i] = 1;
	}
	for (int i = 2; i < 10; i++) {
		dp[i][0] += dp[i - 1][1] * 9 + dp[i - 1][0];
		for (int j = 1; j < 10; j++) {
			dp[i][j] += pow(10, i - 1) + dp[i - 1][j] * 10;
		}
	}

	cin >> N;
	num = stoi(N);
	len = N.size();
	for (int i = 0; i <= len - 1; i++) {
		int digit = N[i] - '0';
		for (int j = 0; j <= 9; j++) {//그 이전 값 저장
			if (i == 0 && j == 0) {
				a[j] += (digit - 1) * dp[len - i - 1][1] + dp[len - i - 1][0];
			}
			else {
				a[j] += digit * dp[len - i - 1][1];
			}
		}
		for (int j = 0; j < digit; j++) {
			if (i == 0 && j == 0) {
				continue;
			}
			a[j] += pow(10, len - i - 1);
		}
		int mod = pow(10, len - i - 1);
		num %= mod;
		a[digit] += num + 1;
	}
	for (int i = 0; i <= 9; i++) {
		cout << a[i] << " ";
	}
}