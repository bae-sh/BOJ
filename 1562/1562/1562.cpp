#include<iostream>
#include<vector>
#include<tuple>
#include<string.h>
#include<map>
#define mod 1000000000
using namespace std;
long long dp[101][10][(1<<10)];//현재 자리, 현재 뒷자리수, 사용
int n;
long long cnt;

long long go(int digit, int num,int use) {
	long long& ans = dp[digit][num][use];
	if (digit == n) {
		if (use == 0b1111111111) {
			return ans = 1;
		}
		else {
			return ans = 0;
		}
	}
	if (ans != -1) {
		return ans;
	}
	int temp;
	ans = 0;
	if (num == 0) {
		temp = (use | (1 << 1));
		return ans = go(digit + 1, 1, temp)%mod;
	}
	else if (num == 9) {
		temp = (use | (1 << 8));
		return ans = go(digit + 1, 8, temp) % mod;

	}
	else {
		temp = (use | (1 << (num - 1)));
		ans = (ans + go(digit + 1, num - 1, temp)) % mod;
		temp = (use | (1 << (num + 1)));
		ans = (ans + go(digit + 1, num + 1, temp)) % mod;
		return ans;
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i < 10; i++) {
		cnt += go(1, i, (1 << i));
		cnt %= mod;
	}
	cout << cnt << "\n";
}