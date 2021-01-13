#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
vector<pair<double, double>> v;
priority_queue <pair<double, pair<double, double>>>pq;
int parent[101];
int n;
double ans;
int find_parent(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find_parent(parent[x]);
}
bool Union(int x, int y) {
	x = find_parent(x);
	y = find_parent(y);
	if (x != y) {
		parent[x] = y;
		return true;
	}
	else {
		return false;
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		double a, b; cin >> a >> b;
		v.push_back({ a,b });
		parent[i] = i;
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			double sum = (v[i].first - v[j].first) * (v[i].first - v[j].first) + (v[i].second - v[j].second) * (v[i].second - v[j].second);
			pq.push({ -sum,{i,j} });
		}
	}
	while (!pq.empty()) {
		double cost = pq.top().first;
		int from = pq.top().second.first;
		int to = pq.top().second.second; pq.pop();
		if (Union(from, to)) {
			ans += sqrt(-cost);
		}
	}
	printf("%.2f", ans);
}