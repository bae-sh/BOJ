#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string.h>
using namespace std;
int N, K;
vector<pair<int,int>> v[100001];
int p[100001][17];
int dpMin[100001][17];
int dpMax[100001][17];
int depth[100001];
void lca(int x, int y) {
	int Max = 0; int Min = 987654321;
	int parent = 0;
	if (depth[x] < depth[y]) {
		swap(x, y);
	}
	int log = 0;
	for (log = 0; (1 << (log + 1)) <= depth[x]; log++);
	for (int i = log; i >= 0; i--) {
		if (depth[x] - (1 << i) >= depth[y]) {
			Max = max(Max, dpMax[x][i]);
			Min = min(Min, dpMin[x][i]);
			x = p[x][i];
		}
	}
	if (x == y) {
		cout << Min << " " << Max << "\n";
	}
	else {
		for (int i = log; i >= 0; i--) {
			if (p[x][i] != 0 && p[x][i] != p[y][i]) {
				Max = max(Max, dpMax[x][i]);
				Min = min(Min, dpMin[x][i]);
				Max = max(Max, dpMax[y][i]);
				Min = min(Min, dpMin[y][i]);
				x = p[x][i];
				y = p[y][i];
			}
		}
		Max = max(Max, dpMax[x][0]);
		Min = min(Min, dpMin[x][0]);
		Max = max(Max, dpMax[y][0]);
		Min = min(Min, dpMin[y][0]);
		cout << Min << " " << Max << "\n";
	}
	return;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int a, b, c; cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	for (int i = 0; i < 100001; i++) {
		for (int j = 0; j < 17; j++) {
			dpMin[i][j] = 987654321;
		}
	}

	queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (auto x : v[cur]) {
			int next = x.first;
			int cost = x.second;
			if (next != 1 && p[next][0] == 0) {
				p[next][0] = cur;
				dpMin[next][0] = dpMax[next][0] = cost;
				depth[next] = depth[cur] + 1;
				q.push(next);
			}
		}
	}

	for (int j = 1; (1 << j) < N; j++) {
		for (int i = 1; i <= N; i++) {
			if (p[i][j-1] != 0) {
				p[i][j] = p[p[i][j - 1]][j - 1];
				if (p[i][j] != 0) {
					dpMin[i][j] = min(dpMin[p[i][j - 1]][j - 1], dpMin[i][j - 1]);
					dpMax[i][j] = max(dpMax[p[i][j - 1]][j - 1], dpMax[i][j - 1]);
				}
			}
		}
	}
	cin >> K;
	for (int i = 0; i < K; i++) {
		int a, b; cin >> a >> b;
		lca(a, b);
	}
}