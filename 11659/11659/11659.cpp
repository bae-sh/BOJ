#include<iostream>
using namespace std;
int sum[1000001];

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int N, M; cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		int x; cin >> x;
		sum[i] = sum[i - 1] + x;
	}
	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		cout << sum[b] - sum[a - 1] << "\n";
	}
}