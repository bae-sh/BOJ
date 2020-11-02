#include<iostream>
#define mod 1000000007
using namespace std;
long long tree[3000000];
long long num[1000001];
int N, M, K;
long long setTree(int n, int s, int e) {
	if (s == e) {
		return tree[n] = num[s];
	}
	int mid = (s + e) / 2;
	return tree[n] = (setTree(n * 2, s, mid) * setTree(n * 2 + 1, mid + 1, e)) % mod;
}
long long newTree(int n, int s, int e,int b,int c) {
	if (s > b || b > e) {
		return tree[n];
	}
	if (s == e) {
		tree[n] = num[s];
		return tree[n];
	}
	int mid = (s + e) / 2;
	return tree[n] = (newTree(n * 2, s, mid, b, c)* newTree(n * 2 + 1, mid + 1, e, b, c)) % mod;
}

long long mutipleTree(int n, int left, int right, int s, int e) {
	if (left <= s && e <= right) {
		return tree[n];
	}
	else if (right < s || e < left) {
		return 1;
	}
	int mid = (s + e) / 2;
	return (mutipleTree(n * 2, left, right, s, mid) * mutipleTree(n * 2 + 1, left, right, mid + 1, e)) % mod;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		cin >> num[i];
	}
	setTree(1, 1, N);

	for (int i = 0; i < M + K; i++) {
		int a, b, c; cin >> a >> b >> c;
		if (a == 1) {
			num[b] = c;
			newTree(1, 1, N, b, c);
		}
		else {
			cout << mutipleTree(1, b, c, 1, N) << "\n";
		}
	}
}