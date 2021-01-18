#include<iostream>
#include<vector>
#include<algorithm>
#define INF 2100000000
using namespace std;
int N, M;
long long tree[300000];
vector<long long> v;
void TreeSet(int start, int end, int index) {
	if (start == end) {
		tree[index] = v[start - 1];
	}
	else {
		int mid = (start + end) / 2;
		TreeSet(start, mid, index * 2);
		TreeSet(mid + 1, end, index * 2 + 1);
		tree[index] = min(tree[index * 2], tree[index * 2 + 1]);
	}
}
int findMin(int start, int end, int index, int left, int right) {
	if (end < left || right < start) return INF;
	if (left <= start && end <= right) return tree[index];
	int mid = (start + end) / 2;
	return min(findMin(start, mid, index * 2, left, right), findMin(mid + 1, end, index * 2 + 1, left, right));
}
int main() {
	ios::sync_with_stdio(false); cout.tie(0); cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int x; cin >> x;
		v.push_back(x);
	}
	TreeSet(1, N, 1);
	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		cout << findMin(1, N, 1, a, b) << "\n";
	}
}