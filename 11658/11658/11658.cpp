#include <iostream>
#include<algorithm>
using namespace std;
int n, m;
int a[1025][1025];
int tree[1025][1025];
int sum(int x,int y) {
	int ans = 0;
	while (x > 0) {
		int ny = y;
		while (ny > 0) {
			ans += tree[x][ny];
			ny -= (ny & -ny);
		}
		x -= (x & -x);
	}
	return ans;
}
void update(int x, int y, int diff) {
	while (x <= n) {
		int ny = y;
		while (ny <= n) {
			tree[x][ny] += diff;
			ny += (ny & -ny);
		}
		x += (x & -x);
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			update(i, j, a[i][j]);
		}
	}
	for (int i = 0; i < m; i++) {
		int w; cin >> w;
		if (w == 0) {
			int x, y, c; cin >> x >> y >> c;
			int diff = c - a[x][y];
			a[x][y] = c;
			update(x, y, diff);
		}
		else {
			int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
			cout << sum(x2, y2) - sum(x1 - 1, y2) - sum(x2, y1 - 1) + sum(x1 - 1, y1 - 1) << "\n";
		}
	}
}