#include<iostream>
using namespace std;

int N, K, S;
int map[401][401];

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		int a, b; cin >> a >> b;
		map[a][b] = 1;
	}
	//floyd
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (map[i][k] && map[k][j]) {
					map[i][j] = 1;
				}
			}
		}
	}
	cin >> S;
	for (int i = 0; i < S; i++) {
		int a, b; cin >> a >> b;
		if (map[a][b]) {
			cout << "-1\n";
		}
		else if (map[b][a]) {
			cout << "1\n";
		}
		else {
			cout << "0\n";
		}
	}
}