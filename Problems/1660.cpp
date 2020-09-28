#include<iostream>
#include<algorithm>
using namespace std;
int a[200] = {0,1};
int b[200] = {0,1};
int dp[300001] ;
int N;
int cnt = 0;
int main() {
	for (int i = 2; i < 200; i++) {
		a[i] = a[i - 1] + i;
		b[i] = b[i - 1] + a[i];
	}

	for (int i = 1; i < 300001; i++) {
		dp[i] = i;
	}

	for (int i = 1; i < 300001; i++) {
		for (int j = 1; j < 200; j++) {
			if (b[j] <= i) {
				dp[i] = min(dp[i], dp[i - b[j]] + 1);
			}
			else {
				break;
			}
		}
	}
	cin >> N;
	cout << dp[N];
}