#include<iostream>
#include<algorithm>
#define INF 2100000000
using namespace std;
int N,M;
int tree[300000];
int num[100001];
int setTree(int n,int s,int e) {
	if (s == e) {
		return tree[n] = num[s];
	}

	int mid = (s + e) / 2;
	return tree[n] = min(setTree(n * 2, s, mid), setTree(n * 2 + 1, mid + 1, e));
}

int findMin(int n, int left, int right, int s, int e) {
	if (left <= s && e <= right) {
		return tree[n];
	}
	else if (right < s || e < left) {
		return INF;
	}
	int mid = (s + e) / 2;
	return min(findMin(n * 2, left, right, s, mid), findMin(n * 2 + 1, left, right, mid + 1, e));
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> num[i];
	}
	setTree(1, 1, N);

	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		cout << findMin(1, a, b, 1, N) << "\n";
	}
}