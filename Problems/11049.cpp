#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int N;
vector<pair<int, int>> v[500];
long long ans;
long long dp[500][500];
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		v[i].push_back(make_pair(x, y));
	}
	for (int i = 2; i <= N; i++) {//°¹¼ö
		for (int start = 0; start <= N - i; start++) {
			int end = start + i - 1;//¸¶Áö¸·ÀÎµ¦½º
			for (int mid = start; mid < end; mid++) {
				int res = dp[start][mid] + dp[mid + 1][end] + v[start].front().first * v[mid].front().second * v[end].front().second;
				if (!dp[start][end] || dp[start][end] > res) dp[start][end] = res;
			}
		}
	}
	printf("%lld", dp[0][N - 1]);
}