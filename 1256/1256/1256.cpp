#include<iostream>
#include<cstring>
#include<algorithm>
#define INF 2100000000
using namespace std;
int N, M;
long long K;
string s = "";
long long c[201][201];
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> M >> K;
	for (int i = 1; i <= 200; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) {
				c[i][j] = 1;
			}
			else if (j > i / 2) {
				c[i][j] = c[i][i - j];
			}
			else {
				c[i][j] = c[i][j - 1] * (i - j + 1) / j;
				if (c[i][j] > INF) {
					c[i][j] = INF;
				}
			}
		}
	}
	int n = N, m = M;
	if (K > c[m + n][n]) {
		cout << "-1\n";
	}
	else {

		for (int i = N + M; i > 0; i--) {
			if (i == 1 || n == 0 || m == 0) {
				if (n > m) {
					s += "a";
					n--;
				}
				else {
					s += "z";
					K -= c[i - 1][m];
					m--;
				}
			}
			else if (K > c[i - 1][m]) {//put a
				s += "z";
				K -= c[i - 1][m];
				m--;
			}
			else {
				s += "a";
				n--;
			}
		}
		cout << s << "\n";
	}
}