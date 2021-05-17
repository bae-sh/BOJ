#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int N, M, Max, idx;
int profit[301][20];
int dp[301][20];//투자금, 인덱스
vector<int> ans[301][20];
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		int temp; cin >> temp;
		for (int j = 0; j < M; j++) {
			cin >> profit[i][j];
		}
	}

	for (int i = 0; i <= N; i++) {
		dp[i][0] = profit[i][0];
		ans[i][0].push_back(i);
	}

	for (int i = 1; i < M; i++) {//회사
		for (int j = 0; j <= N; j++) {//총 투자금
			for (int k = 0; k <= j; k++) {//현재 회사 투자금
				if (dp[j - k][i - 1] + profit[k][i] > dp[j][i]) {
					dp[j][i] = dp[j - k][i - 1] + profit[k][i];
					ans[j][i] = ans[j - k][i - 1];
					ans[j][i].push_back(k);
				}
			}
		}
	}

	cout << dp[N][M - 1] << "\n";
	for (int i = 0; i < M; i++) {
		cout << ans[N][M - 1][i] << " ";
	}
}