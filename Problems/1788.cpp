#include<iostream>
using namespace std;
int f[1000001] = { 0,1,1 };
int n;
const int MAX = 1000000000;
int main() {
	cin >> n;
	for (int i = 3; i < 1000001; i++) {
		f[i] = (f[i - 1] + f[i - 2] ) % MAX;
	}
	if (n > 0) {
		cout << 1 << endl << f[n];
	}
	else if (n == 0) {
		cout << 0 << endl << f[n];
	}
	else {
		n *= -1;
		if (n % 2 == 0) {
			cout << -1 << endl << f[n];
		}
		else {
			cout << 1 << endl << f[n];
		}
	}
	
}