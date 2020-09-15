#include<iostream>
using namespace std;
int N;
int T[10];
int A[10];
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> T[i];
	}
	for (int i = 0; i < N; i++) {
		int t = 0;
		for (int j = 0; j < N; j++) {
			if (A[j] == 0) {
				if (T[i] == t) {
					A[j] = i + 1;
					break;
				}
				else {
					t++;
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		cout << A[i]<<" ";
	}
}