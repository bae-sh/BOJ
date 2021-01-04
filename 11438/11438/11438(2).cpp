#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
#define INF 987654321
using namespace std;
int tree[600000];
vector<int> level;
vector<int> a[100001];
int first[100001];
vector<int> order;
int N, M;
void c(int a[]) {

}
void treeSet(int start, int end, int index) {
	if (start == end) {
		tree[index] = start;
		return;
	}
	int mid = (start + end) / 2;
	treeSet(start, mid, index * 2);
	treeSet(mid + 1, end, index * 2 + 1);
	if (level[tree[index * 2]] < level[tree[index * 2 + 1]]) {
		tree[index] = tree[index * 2];
	}
	else {
		tree[index] = tree[index * 2 + 1];
	}
}
int findTree(int start, int end, int index, int left, int right) {
	if (end < left || right < start) {
		return INF;
	}
	if (left <= start && end <= right) {
		return tree[index];
	}
	int mid = (start + end) / 2;
	int l = findTree(start, mid, index * 2, left, right);
	int r = findTree(mid + 1 , end, index * 2 + 1, left, right);
	if (l == INF) return r;
	else if (r == INF) return l;
	if (level[l] < level[r]) {
		return l;
	}
	else {
		return r;
	}
}
void dfs(int s, int parent,int l) {
	level.push_back(l);
	order.push_back(s);
	for (int x : a[s]) {
		if (x == parent) continue;
		dfs(x, s, l + 1);
		order.push_back(s);
		level.push_back(l);
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int x, y; cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	memset(first, -1, sizeof(first));
	dfs(1, 0, 0);
	treeSet(0, order.size() - 1 , 1);
	for (int i = 0; i < order.size(); i++) {
		int num = order[i];
		if (first[num] == -1) {
			first[num] = i;
		}
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		if (first[a] > first[b]) swap(a, b);
		cout << order[findTree(0, order.size() - 1 , 1, first[a], first[b])] << "\n";
	}
}