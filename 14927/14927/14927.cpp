#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int n;
int map[18][18];
int temp[18][18];
int dx[] = { -1,0,1,0,0 };
int dy[] = { 0,1,0,-1,0 };
int ans = -1;
int cnt;
void change(int x, int y) {
	for (int i = 0; i < 5; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < n && 0 <= ny && ny < n) {
			temp[nx][ny] ^= 1;
		}
	}
	cnt++;
}
int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < (1 << n); i++) {
		memcpy(temp, map, sizeof(temp));
		cnt = 0;
		for (int j = 0; j < n; j++) {
			if ((i & (1 << j)) != 0) {
				change(0, n - 1 - j);
				
			}
		}
		for (int j = 1; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (temp[j - 1][k] == 1) {
					change(j, k);
				}
			}
		}
		bool all = true;
		for (int j = 0; j < n; j++) {
			if (temp[n - 1][j] == 1) {
				all = false;
				break;
			}
		}
		if (all) {
			ans = (ans == -1) ? cnt : min(ans, cnt);
		}
	}
	cout << ans << '\n';
}