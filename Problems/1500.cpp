#include<iostream>
int S, K;
int D[20];
long long ans = 1;
using namespace std;

int main() {
	cin >> S >> K;
	int temp = S / K;
	for (int i = 0; i < K; i++) {
		D[i] = temp;
	}
	for (int i = 0; i < S%K; i++) {
		D[i]++;
	}
	for (int i = 0; i < K; i++) {
		ans *= D[i];
	}
	cout << ans;
}