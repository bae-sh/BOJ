#include<iostream>
using namespace std;
int x, y, a, b, ans;
int gcd(int x, int y) {
	int n;
	while (y != 0) {
		n = x % y;
		x = y;
		y = n;
	}
	return x;
}
int main() {
	cin >> x >> y;
	if (x == y) {
		cout << x;
		return 0;
	}
	else if (x < y) {
		int temp = x;
		x = y;
		y = temp;
	}
	int k = gcd(x, y);
	a = x / k;
	b = y / k;
	cout << (a + b - 1)*k;
}