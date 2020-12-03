#include<iostream>
#include<cstring>
#include<vector>
#define INF 987654321
using namespace std;
int T;
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> T;
	while (T-- > 0) {
		int N, M, W;
		cin >> N >> M >> W;
		long long Dist[501];
		vector<pair<int, pair<int, int>>> v;
		bool negative_cycle = false;
		fill(Dist, Dist + 501, 0);
		for (int i = 0; i < M; i++) {
			int s, e, t; cin >> s >> e >> t;
			v.push_back({ s,{e,t} });
			v.push_back({ e,{s,t} });
		}
		for (int i = 0; i < W; i++) {
			int s, e, t; cin >> s >> e >> t;
			v.push_back({ s,{e,-t} });
		}

		for (int i = 1; i <= N; i++) {
			for (int j = 0; j < v.size(); j++) {
				int from = v[j].first;
				int to = v[j].second.first;
				int cost = v[j].second.second;
				if (Dist[to] > Dist[from] + cost) {
					Dist[to] = Dist[from] + cost;
					if (i == N) {
						negative_cycle = true;
					}
				}
			}
		}
		if (negative_cycle) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
}