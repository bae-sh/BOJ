#include<iostream>
using namespace std;
int T;
long long c[22][22];
long long Tall[21];
long long Short[21];
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	for (int i = 1; i <= 20; i++) {
		c[i][i] = c[i][0] = 1;
		for (int j = 1; j < i; j++) {
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
		}
	}
	Tall[0] = 1; Short[0] = 1;
	Tall[1] = 1; Short[1] = 1;
	for (int i = 2; i <= 20; i++) {
		for (int k = 1; k <= i; k ++) {
			if (k % 2 == 1) {
				Tall[i] += Tall[k - 1] * Short[i - k] * c[i-1][k - 1];
			}
			else {
				Short[i] += Short[k - 1] * Short[i - k] * c[i-1][k - 1];
			}
		}
	}
	cin >> T;
	while (T--) {
		int N; cin >> N;
		if (N == 1) {
			cout << "1\n";
		}
		else {
			cout << Tall[N] + Short[N] << "\n";
		}
	}
}