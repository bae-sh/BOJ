#include<iostream>
#include<algorithm>
using namespace std;
int A, B;
int main() {
	int temp;
	for (int i = 0; i < 4; i++) {
		cin >> temp;
		A += temp;
	}
	for (int i = 0; i < 4; i++) {
		cin >> temp;
		B += temp;
	}
	cout << max(A, B);
}