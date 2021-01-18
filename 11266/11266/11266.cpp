#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
int V, E;
vector<int> v[10001];
int discovered[10001];
bool isCut[10001];
int number;

int dfs(int cur, bool isRoot) {
	discovered[cur] = ++number;
	int ret = discovered[cur];
	int child = 0;

	for (int i = 0; i < v[cur].size(); i++) {
		int next = v[cur][i];
		if (discovered[next]) {
			ret = min(ret, discovered[next]);
			continue;
		}
		child++;
		int prev = dfs(next, false);
		if (!isRoot && prev >= discovered[cur]) {
			isCut[cur] = true;
		}
		ret = min(ret, prev);
	}
	if (isRoot) {
		isCut[cur] = (child >= 2);
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
			dfs(i, true);
		}
	}
	int cnt = 0;
	for (int i = 1; i <= V; i++) {
		if (isCut[i]) {
			cnt++;
		}
	}
	cout << cnt << "\n";
	for (int i = 1; i <= V; i++) {
		if (isCut[i]) {
			cout << i << " ";
		}
	}
}