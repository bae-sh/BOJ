#include<iostream>
using namespace std;
int dp[10000001] = {0,5};
int N;

int main() {
	cin >> N;
	for (int i = 2; i < 10000001; i++) {
		dp[i] = (3 * i + 1 + dp[i - 1]) % 45678;
	}
	cout << dp[N];
}