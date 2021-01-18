#include<iostream>
#include<algorithm>
using namespace std;
int t;
int n, m;
int idx[200001];
int tree[600000];
int treeSet(int index, int start, int end) {
	if (start == end) {
		if (start <= m) {
			return tree[index] = 0;
		}
		else {
			return tree[index] = 1;
		}
	}
	int mid = (start + end) / 2;
	return tree[index] = treeSet(index * 2, start, mid) + treeSet(index * 2 + 1, mid + 1, end);
}
int movie(int index, int target, int start, int end, int diff) {
	if (target < start || end < target) {
		return 0;
	}
	tree[index]--;
	if (start == end) {
		return diff;
	}
	int mid = (start + end) / 2;
	return max(movie(index * 2, target, start, mid, diff), movie(index * 2 + 1, target, mid + 1, end, diff + tree[index * 2]));
}
void Plus(int index, int target, int start, int end) {
	if (target < start || end < target) {
		return;
	}
	tree[index]++;
	if (start == end) {
		return;
	}
	int mid = (start + end) / 2;
	Plus(index * 2, target, start, mid);
	Plus(index * 2 + 1, target, mid + 1, end);
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = m + 1; i <= m + n; i++) {
			idx[i - m] = i;
		}
		treeSet(1, 1, n + m);
		for (int i = m; i > 0; i--) {
			int target; cin >> target;
			cout << movie(1, idx[target], 1, n + m, 0) << " ";
			idx[target] = i;
			Plus(1, i, 1, m + n);
		}
		cout << "\n";
	}
}