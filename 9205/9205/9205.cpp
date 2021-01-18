#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<queue>
#include<string.h>
using namespace std;
int t, n;

int cal(pair<int,int> p1, pair<int, int> p2) {
	return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int main() {
	ios::sync_with_stdio(false); cout.tie(0); cout.tie(0);

	cin >> t;
	while (t--) {
		cin >> n;
		pair<int, int> s; cin >> s.first>>s.second;
		vector<pair<int, int>> v;
		queue<pair<int, int>> q;
		bool check[101];
		memset(check, 0, sizeof(check));
		bool alive = false;
		for (int i = 0; i < n; i++) {
			int a, b; cin >> a >> b;
			v.push_back({ a,b });
		}
		pair<int, int> e; cin >> e.first >> e.second;

		q.push(s);
		while (!q.empty()) {
			auto cur = q.front(); q.pop();
			if (cal(cur, e) <= 1000) {
				alive = true;
				break;
			}
			for (int i = 0; i < v.size(); i++) {
				if (cal(cur, v[i]) <= 1000&& !check[i]) {
					q.push(v[i]);
					check[i] = true;
				}
			}
		}
		if (alive) {
			cout << "happy\n";
		}
		else {
			cout << "sad\n";
		}
	}
}