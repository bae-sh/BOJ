#include<iostream>
#include<cstring>
using namespace std;
char c[100][100];
bool d[100][100];
int N;
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> c[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (c[i][j] == 'Y' && c[j][i] == 'N') {
				d[i][j] = true;
			}
		}
	}
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (d[i][k] && d[k][j]) d[i][j] = true;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		if (d[i][i]) {
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	return 0;
}