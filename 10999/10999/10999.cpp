#include<iostream>
#include<algorithm>
using namespace std;
int N, M, K;
long long tree[4000000];
long long lazy[4000000];
void update_lazy(int index, int start, int end) {
	if (lazy[index] != 0) {
		tree[index] += (end - start + 1) * lazy[index];
		if (start != end) {
			lazy[index * 2] += lazy[index];
			lazy[index * 2 + 1] += lazy[index];
		}
		lazy[index] = 0;
	}
}
void setTree(int index,int num,int target, int start,int end) {
	if (target < start || end < target) return;
	tree[index] += num;
	if (start == end) return;
	int mid = (start + end) / 2;
	setTree(index * 2, num, target, start, mid);
	setTree(index * 2 + 1, num, target, mid + 1, end);
}

void update(int index, int left,int right, int start, int end,long long diff) {
	update_lazy(index, start, end);
	if (end < left || right < start) return;
	if (left <= start && end <= right) {
		tree[index] += (end - start + 1) * diff;
		if (start != end) {
			lazy[index * 2] += diff;
			lazy[index * 2 + 1] += diff;
		}
		return;
	}
	if (start == end) return;
	int mid = (start + end) / 2;
	update(index * 2, left, right, start, mid, diff);
	update(index * 2 + 1, left, right, mid + 1, end, diff);
	tree[index] = tree[index * 2] + tree[index * 2 + 1];
}

long long sumTree(int index, int left, int right, int start, int end) {
	update_lazy(index, start, end);
	if (right < start || end < left) return 0;
	if (left <= start && end <= right) return tree[index];
	int mid = (start + end) / 2;
	return sumTree(index * 2, left, right, start, mid) + sumTree(index * 2 + 1, left, right, mid + 1, end);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		long long num; cin >> num;
		setTree(1, num, i, 1, N);
	}
	for (int i = 0; i < M + K; i++) {
		int a, b, c; cin >> a >> b >> c;
		if (a == 1) {
			long long d; cin >> d;
			update(1, b, c, 1, N, d);
		}
		else {
			cout << sumTree(1, b, c, 1, N) << "\n";
		}
	}
}