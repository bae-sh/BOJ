#include<iostream>
#include<string.h>
#define mod 10000003
using namespace std;
int N;
int num[101];
int dp[101][100001];
int Euclidean(int a, int b)
{
	return a % b ? Euclidean(b, a % b) : b;
}

long long go(int len, int gcd) {//최대 공배수
	long long ans = 0;
	if (len >= N) {
		if (gcd == 1) {
			return 1;
		}
		else {
			return 0;
		}
	}
	if (dp[len][gcd] != -1) {
		return dp[len][gcd];
	}
	dp[len][gcd] = 0;
	if (gcd == 0) {
		ans += go(len + 1, num[len]);
	}
	else {
		int temp = Euclidean(gcd, num[len]);
		ans += go(len + 1, temp);
	}

	ans %= mod;
	ans += go(len + 1, gcd);
	ans %= mod;
	dp[len][gcd] = ans;
	return ans;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	memset(dp, -1, sizeof(dp));
	cout << go(0, 0) << "\n";
}