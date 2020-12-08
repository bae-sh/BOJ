#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef vector<vector<bool>> matrix;
matrix operator *(const matrix& a, const matrix& b) {
	int n = a.size();
	matrix c(n, vector<bool>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (a[i][k] && b[k][j]) {
					c[i][j] = true;
				}
			}
		}
	}
	return c;
}

int N, K, M;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> K >> M;
	matrix t(N, vector <bool>(N));
	for (int i = 0; i < N; i++) {
		int a, b; cin >> a >> b;
		t[i][a - 1] = true;
		t[i][b - 1] = true;
	}
	matrix ans(N, vector<bool>(N));
	for (int i = 0; i < N; i++) {
		ans[i][i] = true;
	}

	while (K > 0) {
		if (K & 1) {
			ans = ans * t;
		}
		t = t * t;
		K >>= 1;
	}
	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		if (ans[a - 1][b - 1]) {
			cout << "death\n";
		}
		else {
			cout << "life\n";
		}
	}
}