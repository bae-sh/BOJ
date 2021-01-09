#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
long long ans;
int n;
int parent[100000];
vector<pair<int, int>> v[3];
vector < pair<int, pair<int, int>>> edge;
int find(int x) {
	if (x == parent[x]) {
		return x;
	}
	else {
		return parent[x] = find(parent[x]);
	}
}
void Union(int x, int y) {
	x = find(x);
	y = find(y);
	parent[x] = y;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y, z; cin >> x >> y >> z;
		v[0].push_back({ x,i });
		v[1].push_back({ y,i });
		v[2].push_back({ z,i });
		parent[i] = i;
	}
	sort(v[0].begin(), v[0].end());
	sort(v[1].begin(), v[1].end());
	sort(v[2].begin(), v[2].end());

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < 3; j++) {
			edge.push_back({ abs(v[j][i].first - v[j][i + 1].first),{v[j][i].second,v[j][i + 1].second} });
		}
	}
	sort(edge.begin(), edge.end());
	for (int i = 0; i < edge.size(); i++) {
		int cost = edge[i].first;
		int from = edge[i].second.first;
		int to = edge[i].second.second;
		if (find(from) != find(to)) {
			Union(from, to);
			ans += cost;
		}
	}
	cout << ans << "\n";
}