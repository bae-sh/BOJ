#include<iostream>
#include<algorithm>
using namespace std;
int A, B, C, D, P;
int X, Y;
int main() {
	cin >> A >> B >> C >> D >> P;
	X = A * P;
	Y = B;
	if (P > C) {
		Y += (P - C)*D;
	}
	cout << min(X, Y);
}