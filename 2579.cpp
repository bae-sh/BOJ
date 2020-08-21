#include<iostream>
#include<algorithm>

int main() {
	int n;
	std::cin >> n;
	int *stair = new int[n+1];
	for (int i = 1; i <= n; i++) {
		std::cin >> stair[i];
	}
	int *dp = new int[n + 1];
	if (n == 1) {
		std::cout << stair[1] << std::endl;
		exit(0);
	}
	dp[1] = stair[1];
	dp[2] = stair[1] + stair[2];
	for (int i = 3; i <= n; i++) {
		dp[i] = std::max(dp[i - 2] + stair[i], dp[i - 3] + stair[i - 1] + stair[i]);

	}
	std::cout << dp[n];
}