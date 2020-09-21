#include<iostream>
using namespace std;
int N;
int time[20];
int Y, M;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> time[i];
		if (time[i] > 0) {
			Y += 10, M += 15;
		}
		Y += (time[i] / 30) * 10;
		M += (time[i] / 60) * 15;
	}
	if (Y < M) {
		cout << "Y " << Y;
	}
	else if (Y > M) {
		cout << "M " << M;
	}
	else {
		cout << "Y M " << Y;
	}
}