#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int N;
int a[1000001];
int order[500001];
int tree[2000000];
long long ans;
void update(int index, int target, int start, int end) {
	if (start <= target && target <= end) {
		tree[index]++;
	}
	else {
		return;
	}
	if (start == end) return;
	int mid = (start + end) / 2;
	update(index * 2, target, start, mid);
	update(index * 2 + 1, target, mid + 1, end);
}

int findTree(int index, int start, int end, int left, int right) {
	if (end < left || right < start) {
		return 0;
	}
	if (left <= start && end <= right) {
		return tree[index];
	}
	if (start == end) {
		return tree[index];
	}
	int mid = (start + end) / 2;
	return findTree(index * 2, start, mid, left, right) + findTree(index * 2 + 1, mid + 1, end, left, right);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x; cin >> x;
		a[x] = i;
	}
	for (int i = 0; i < N; i++) {
		int x; cin >> x;
		order[a[x]] = i;
	}
	for (int i = 0; i < N; i++) {
		int index = order[i];
		ans += findTree(1, 0, N - 1, index, N - 1);
		update(1, index, 0, N - 1);
	}
	cout << ans << "\n";
}