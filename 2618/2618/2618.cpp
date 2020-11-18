#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

int N, W;
int dp[1001][1001];
vector<pair<int, int>> v;
int sol(int first, int second) {
	if (first == W || second == W) {
		return 0;
	}
	if (dp[first][second] != -1) {
		return dp[first][second];
	}
	int dist1, dist2;
	int next = max(first, second) + 1;
	if (first == 0) {
		dist1 = abs(v[next].first - 1) + abs(v[next].second - 1);
	}
	else {
		dist1 = abs(v[next].first - v[first].first) + abs(v[next].second - v[first].second);
	}
	if (second == 0) {
		dist2 = abs(v[next].first - N) + abs(v[next].second - N);
	}
	else {
		dist2 = abs(v[next].first - v[second].first) + abs(v[next].second - v[second].second);
	}
	int left = sol(next, second) + dist1;
	int right = sol(first, next) + dist2;
	dp[first][second] = min(left, right);
	return dp[first][second];
}
void trace(int first, int second) {
	if (first == W || second == W) {
		return;
	}
	int dist1, dist2;
	int next = max(first, second) + 1;
	if (first == 0) {
		dist1 = abs(v[next].first - 1) + abs(v[next].second - 1);
	}
	else {
		dist1 = abs(v[next].first - v[first].first) + abs(v[next].second - v[first].second);
	}
	if (second == 0) {
		dist2 = abs(v[next].first - N) + abs(v[next].second - N);
	}
	else {
		dist2 = abs(v[next].first - v[second].first) + abs(v[next].second - v[second].second);
	}
	if (dp[next][second] + dist1 > dp[first][next] + dist2) {
		cout << "2\n";
		trace(first, next);
	}
	else {
		cout << "1\n";
		trace(next, second);
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> W;
	v.push_back({ 0,0 });
	for (int i = 0; i < W; i++) {
		int a, b; cin >> a >> b;
		v.push_back({ a,b });
	}
	memset(dp, -1, sizeof(dp));
	cout << sol(0, 0) << "\n";
	trace(0, 0);

}