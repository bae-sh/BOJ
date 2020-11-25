#include<iostream>
#include<algorithm>
#define INF 2100000000
using namespace std;
int N, M;
int num[100001];
int maxTree[300000];//�ִ밪
int minTree[300000];
int setMaxTree(int n,int s,int e) {
	if (s == e) {
		return maxTree[n] = num[s];
	}
	
	int mid = (s + e) / 2;
	return maxTree[n] = max(setMaxTree(n * 2, s, mid), setMaxTree(n * 2 + 1, mid + 1, e));
	
}
int setMinTree(int n, int s, int e) {
	if (s == e) {
		return minTree[n] = num[s];
	}

	int mid = (s + e) / 2;
	return minTree[n] = min(setMinTree(n * 2, s, mid), setMinTree(n * 2 + 1, mid + 1, e));

}
int findMax(int n, int left, int right, int s, int e) {
	
	if (left <= s && e <= right) {
		return maxTree[n];
	}
	else if (right < s || e < left) {
		return -INF;
	}
	int mid = (s + e) / 2;
	return max(findMax(n * 2, left, right, s, mid), findMax(n * 2 + 1, left, right, mid + 1, e));
}
int findMin(int n, int left, int right, int s, int e) {
	if (left <= s && e <= right) {
		return minTree[n];
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
	setMaxTree(1, 1, N); setMinTree(1, 1, N);
	for (int i = 0; i < M; i++) {
		int left, right; cin >> left >> right;
		cout << findMin(1, left, right, 1, N) << " " << findMax(1, left, right, 1, N) << "\n";
	}
}