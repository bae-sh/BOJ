#include<iostream>
using namespace std;
int T;
int main() {
	cin >> T;
	while (T-->0) {
		int N,M;
		cin >> N;
		int *coin = new int[N];
		for (int i = 0; i < N; i++) {
			cin >> coin[i];
		}
		cin >> M;
		int *dp = new int[M + 1];
		for (int i = 0; i < M + 1; i++) {
			dp[i] = 0;
		}
		dp[0] = 1;
		for (int i = 0; i < N; i++) {
			for (int j = coin[i]; j <= M; j++) {
				dp[j] += dp[j - coin[i]];
			}
		}
		cout << dp[M]<<"\n";
	}
}