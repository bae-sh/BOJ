#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#define INF 987654321

using namespace std;
int N, M;
long long Dist[501];
bool negative_cycle;
vector<pair<int, pair<int, int>>> v;//from to cost

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> M;
	fill(Dist, Dist + 501, INF);
	for (int i = 0; i < M; i++) {
		int a, b, c; cin >> a >> b >> c;
		v.push_back({ a,{b,c} });
	}
	Dist[1] = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			int from = v[j].first;
			int to = v[j].second.first;
			int cost = v[j].second.second;
			if (Dist[from] != INF && Dist[to] > Dist[from] + cost) {
				Dist[to] = Dist[from] + cost;
				if (i == N) {
					negative_cycle = true;
				}
			}
		}
	}
	if (negative_cycle) {
		cout << -1;
	}
	else {
		for (int i = 2; i <= N; i++) {
			if (Dist[i] == INF) {
				cout << -1 << "\n";
			}
			else {
				cout << Dist[i] << "\n";
			}
		}
	}
}