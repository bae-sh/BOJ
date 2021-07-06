#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n, m, ans;
int parent[500001];
int find_parent(int x) {
	if (x == parent[x]) return x;
	return parent[x] = find_parent(parent[x]);
}
bool Union(int x, int y) {
	x = find_parent(x);
	y = find_parent(y);
	if (x == y) {
		return false;
	}
	parent[x] = y;
	return true;
}
vector<pair<int, int>> v;
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		v.push_back({ a,b });
	}
	for (int i = 0; i < v.size(); i++) {
		int a = v[i].first;
		int b = v[i].second;
		if (!Union(a, b)) {
			ans = i + 1;
			break;
		}
	}
	cout << ans << "\n";
}