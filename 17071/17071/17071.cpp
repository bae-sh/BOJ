#include<iostream>
#include<algorithm>
#include<vector>
#include<tuple>
#include<queue>
#include<string.h>
using namespace std;
int N, K, time;
int d[500001][2];

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int N, K; cin >> N >> K;
	memset(d, -1, sizeof(d));
	queue<pair<int,int>> q;//¼öºó ½Ã°£
	q.push({ N,0 });
	d[N][0] = 0;
	while (!q.empty()) {
		int pos, time; tie(pos, time) = q.front(); q.pop();
		for (int y : {pos + 1, pos - 1, pos * 2}) {
			if (0 <= y && y <= 500000&&d[y][(time + 1) % 2] == -1) {
				d[y][(time + 1) % 2] = time + 1;
				q.push({ y,time + 1 });
			}
		}
	}
	int t = 0;
	while (K <= 500000) {
		if (d[K][t % 2] <= t) {
			cout << t << "\n";
			return 0;
		}
		else {
			t++;
			K += t;
		}
	}
	cout << -1 << "\n";
}