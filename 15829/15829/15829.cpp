#include<iostream>
#include<string>
#define mod 1234567891
using namespace std;
int L;
string s;
long long r[51];
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> L >> s;
	long long ans = 0;
	r[0] = 1; r[1] = 31;
	for (int i = 2; i < L; i++) {
		r[i] = (r[i - 1] * r[1]) % mod;
	}
	for (int i = 0; i < L; i++) {
		int a = s[i] - 'a' + 1;
		ans += (a * r[i]);
		ans %= mod;
	}
	cout << ans << "\n";
}