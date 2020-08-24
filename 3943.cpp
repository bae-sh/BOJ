#include<iostream>
#include<algorithm>
using namespace std;
int t;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	int dp[100000];
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		int MAX = n;
		while (n != 1) {
			if (n % 2 == 0) {
				n /= 2;
			}
			else {
				n = n * 3 + 1;
				MAX = max(MAX, n);
			}
		}
		dp[i] = MAX;
	}
	for (int i = 0; i < t; i++) {
		cout << dp[i] << "\n";
	}
}