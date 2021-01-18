#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int V, E;
int discovered[100001];
vector<int> v[100001];
vector<pair<int, int>> isCut;
int cnt;
int dfs(int cur, int parent) {
	discovered[cur] = ++cnt;
	int ret = discovered[cur];
	for (int i = 0; i < v[cur].size(); i++) {
		int next = v[cur][i];
		if (next == parent) continue;

		if (discovered[next]) {
			ret = min(ret, discovered[next]);
			continue;
		}
		int prev = dfs(next, cur);
		if (prev > discovered[cur]) {
			isCut.push_back({ min(cur,next),max(cur,next) });
		}
		ret = min(ret, prev);
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= V; i++) {
		if (!discovered[i]) {
			dfs(i, 0);
		}
	}
	sort(isCut.begin(), isCut.end());
	cout << isCut.size() << "\n";
	for (int i = 0; i < isCut.size(); i++) {
		cout << isCut[i].first << " " << isCut[i].second << "\n";
	}
}