#include<iostream>
#include<algorithm>
#define INF 987654321
using namespace std;
int N, M, B;
int map[501][501];
int time = INF; int height = INF;
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> M >> B;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	for (int k = 0; k <= 256; k++) {
		int block = B; int t = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] > k) {
					block += map[i][j] - k;
					t += (map[i][j] - k) * 2;
				}
				else if (map[i][j] < k) {
					block -= k - map[i][j];
					t += (k - map[i][j]);
				}
			}
		}
		if (block >= 0) {
			if (time >= t) {
				time = t;
				height = k;
			}
		}
		else {
			break;
		}
	}
	cout << time << " " << height << "\n";
}