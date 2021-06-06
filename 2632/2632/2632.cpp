#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int s, m, n;
long long ans;
int sum[1000001] = { 1 };
vector<int> A;
vector<int> B;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> s >> m >> n;
	for (int i = 0; i < m; i++) {
		int x; cin >> x;
		A.push_back(x);
	}
	for (int i = 0; i < m; i++) {
		int x = A[i];
		sum[x]++;
		for (int j = i + 1; j < m; j++) {
			x += A[j];
			sum[x]++;
		}
		for (int j = 0; j < i - 1; j++) {
			x += A[j];
			sum[x]++;
		}
	}

	ans += sum[s];
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		B.push_back(x);
	}
	for (int i = 0; i < n; i++) {
		int x = B[i];
		if (s - x >= 0) {
			ans += sum[s - x];
		}
		for (int j = i + 1; j < n; j++) {
			x += B[j];
			if (s - x >= 0) {
				ans += sum[s - x];
			}
		}
		for (int j = 0; j < i - 1; j++) {
			x += B[j];
			if (s - x >= 0) {
				ans += sum[s - x];
			}
		}
	}
	cout << ans << "\n";
}