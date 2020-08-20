#include <iostream>
#include <algorithm>

using namespace std;
int N;
int pole[501];
int dp[501];
int Max = 0;
int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		pole[b] = a;
	}
	for (int i = 1; i < 501; i++) {
		if(pole[i]!=0)
			dp[i] = 1;
		for (int j = 1; j < i; j++) {
			if (pole[j] < pole[i]) {
				dp[i] = max(dp[i],dp[j] + 1);
				Max = max(Max, dp[i]);
			}
		}
	}
	cout << N-Max;
}