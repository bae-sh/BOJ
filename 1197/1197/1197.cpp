#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int V, E, ans;
int p[10001];
vector<pair<int,pair<int, int>>> v;
int Find(int x) {
	if (x == p[x]) {
		return x;
	}
	else {
		return p[x] = Find(p[x]);
	}
}
void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	p[x] = y;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> V >> E;
	for (int i = 1; i <= V; i++) {
		p[i] = i;
	}
	for (int i = 0; i < E; i++) {
		int a, b, c; cin >> a >> b >> c;
		v.push_back({ c,{ a,b } });
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < E; i++) {
		int from = v[i].second.first;
		int to = v[i].second.second;
		if (Find(from) != Find(to)) {
			Union(from, to);
			ans += v[i].first;
		}
	}
	cout << ans;
}