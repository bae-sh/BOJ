#include<iostream>
using namespace std;
int n;
int d[3] = {1};
int ans;
int gcd(int a, int b) {
	if (a < b) {
		int t = a;
		a = b;
		b = t;
	}
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> d[i];
	}
	if (n == 2) {
		ans = gcd(d[0], d[1]);
	}
	else {
		ans = gcd(gcd(d[0], d[1]), d[2]);
	}
	for (int i = 1; i <= ans; i++) {
		if (ans%i == 0) {
			cout << i << "\n";
		}
	}
}