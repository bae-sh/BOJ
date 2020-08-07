#include<iostream>
#include<algorithm>
using namespace std;
int n;
int MAX;
int main() {
	cin >> n;
	int *box = new int[n];
	int *dp = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> box[i];
		dp[i] = 1;
	}
	MAX = 1;
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if (box[j] > box[i]) {
				dp[j] = max(dp[j], dp[i] + 1);
				MAX = max(MAX, dp[j]);
			}
		}
	}
	cout << MAX;
}