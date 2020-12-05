#include<iostream>
#include<vector>

using namespace std;
int N;
int cost[20][20];
int a[20][20];
int ans;
bool error;
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> cost[i][j];
		}
	}
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (i == k || j == k) continue;
				if (cost[i][j] == cost[i][k] + cost[k][j]) {
					a[i][j] = 1;//단일경로 x
				}
				else if (cost[i][j] > cost[i][k] + cost[k][j] || (cost[i][j] != cost[j][i])) {
					error = true;
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (a[i][j] == 0) {
				ans += cost[i][j];
			}
		}
	}
	if (error) {
		cout << -1;
	}
	else {
		cout << ans;
	}
}