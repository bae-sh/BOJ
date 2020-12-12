#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M, cnt, ans;
int p[100001];
vector<pair<int,pair<int, int>>> v;
int Find(int x) {
	if (p[x] == x) return x;
	else return p[x] = Find(p[x]);
}
void Union(int x, int y) {
	int parent_x = Find(x);
	int parent_y = Find(y);
	p[parent_x] = parent_y;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c; cin >> a >> b >> c;
		v.push_back({ c,{a,b} });
	}
	for (int i = 0; i <= N; i++) {
		p[i] = i;
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		int cost = v[i].first;
		int from = v[i].second.first;
		int to = v[i].second.second;
		if (Find(from) != Find(to)) {
			Union(from, to);
			cnt++;
			ans += cost;
		}
		if (cnt == N - 2) {
			cout << ans << "\n";
			return 0;
		}
	}
}