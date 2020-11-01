#include<iostream>

using namespace std;

int N, M, K;
long long num[1000001];
long long tree[3000000];
long long treeSet(int n, int s,int e) {
	if (s == e) {
		return tree[n] = num[s];
	}
	int mid = (s + e) / 2;
	tree[n] = treeSet(n * 2, s, mid) + treeSet(n * 2 + 1, mid + 1, e);
	return tree[n];

}
void update(int n, int s, int e, int b, long long dif) {
	if (s <= b && b <= e) {
		tree[n] += dif;
	}
	else {
		return;
	}
	if (s == e) {
		return;
	}
	int mid = (s + e) / 2;
	update(n * 2, s, mid, b, dif);
	update(n * 2 + 1, mid + 1, e, b, dif);
}
long long sum(int n,int left,int right,int s,int e) {
	if (left <= s && e <= right) {
		return tree[n];
	}
	if (e < left || right < s) {
		return 0;
	}
	int mid = (s + e) / 2;
	return sum(n * 2, left, right, s, mid) + sum(n * 2 + 1, left, right, mid + 1, e);
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		cin >> num[i];
	}
	treeSet(1, 1, N);

	for (int i = 0; i < M + K; i++) {
		int a, b; cin >> a >> b;
		if (a == 1) {
			long long c; cin >> c;
			long long dif = c - num[b];
			num[b] = c;
			update(1, 1, N, b, dif);
		}
		else {
			int c; cin >> c;
			cout << sum(1, b, c, 1, N) << "\n";
		}
	}
}