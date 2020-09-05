#include<iostream>
using namespace std;
int N, X;
int main() {
	cin >> N;
	while (N-- > 0) {
		int t;
		cin >> t;
		if (t) {
			X++;
		}
		else {
			X--;
		}
	}
	if (X > 0) {
		cout << "Junhee is cute!";
	}
	else {
		cout << "Junhee is not cute!";
	}
}