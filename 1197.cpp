#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;
vector<pair<int, pair<int, int>>> v;
int V, E, ans;
int parent[10001];
int findParent(int x) {
	if (parent[x] == x) return x;
	else return parent[x] = findParent(parent[x]);
}
int main() {
	scanf("%d %d", &V, &E);
	for (int i = 0; i < E; i++) {
		int A, B, C;
		scanf("%d %d %d", &A, &B, &C);
		v.push_back(make_pair(C, make_pair(A, B)));
	}
	sort(v.begin(), v.end());
	for (int i = 1; i <= V; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < E; i++) {
		int from = findParent(v[i].second.first);
		int to = findParent(v[i].second.second);
		if (from != to) {
			parent[to] = parent[from];
			ans += v[i].first;
		}
	}
	printf("%d", ans);
}