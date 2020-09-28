#include<iostream>
using namespace std;
int R, B, L, W;

int main() {
	cin >> R >> B;
	for (int i = 1;; i++) {
		L = i;
		W = (R + 4 - 2 * L) / 2;
		if (L*W == R + B) {
			if (L > W) {
				cout << L << " " << W;
			}
			else {
				cout << W << " " << L;
			}
			break;
		}
	}
}