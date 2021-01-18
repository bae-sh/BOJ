#include<iostream>
#include<vector>
#include<algorithm>
#define INF 2100000000
using namespace std;
int tree[300000];
int num[300000];
int N, M;
int treeSet(int start, int end, int index) {
	if (start == end) {
		return tree[index] = num[end];
	}
	int mid = (start + end) / 2;
	return tree[index] = min(treeSet(start, mid, index * 2), treeSet(mid + 1, end, index * 2 + 1));
}
int findMin(int start, int end, int index, int left, int right) {
	if (end < left || right < start) return INF;
	if (left <= start && end <= right) return tree[index];
	int mid = (start + end) / 2;
	return min(findMin(start, mid, index * 2, left, right), findMin(mid + 1, end, index * 2 + 1, left, right));
}
int update(int start, int end, int index, int new_index, int new_value) {
	if (new_index < start || end < new_index) return tree[index];
	if (start == end) return tree[index] = new_value;
	int mid = (start + end) / 2;
	return tree[index] = min(update(start, mid, index * 2, new_index, new_value), update(mid + 1, end, index * 2 + 1, new_index, new_value));

	
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> num[i];
	}
	treeSet(1, N, 1);
	cin >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c; cin >> a >> b >> c;
		if (a == 1) {
			update(1, N, 1, b, c);
		}
		else {
			cout << findMin(1, N, 1, b, c) << "\n";
		}
	}
}