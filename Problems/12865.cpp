#include<iostream>
#include<algorithm>
using namespace std;
int N, K;
int *W, *V;
int dp[100001];
int main() {
	cin >> N >> K;
	W = new int[N];
	V = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> W[i] >> V[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = K; j >= 1; j--) {
			if (W[i] <= j) {
				dp[j] = max(dp[j], dp[j - W[i]] + V[i]);
			}
		}
	}
	cout << dp[K];
	return 0;
}