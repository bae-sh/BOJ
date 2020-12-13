#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
int T;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int main() {
	ios::sync_with_stdio(false); cout.tie(0); cin.tie(0);

	cin >> T;
	while (T--) {
		int ans = 0;
		bool keys[26]; memset(keys, false, sizeof(keys));
		char map[102][102];
		bool check[102][102]; memset(check, false, sizeof(check));
		queue < pair<int, int>> q;
		queue<pair<int, int>> al[26];
		int h, w; cin >> h >> w;
		for (int i = 0; i < 102; i++) {
			for (int j = 0; j < 102; j++) {
				map[i][j] = '.';
			}
		}

		for (int i = 1; i <= h; i++) {
			string s; cin >> s;
			for (int j = 1; j <= w; j++) {
				map[i][j] = s[j-1];
			}
		}
		string s; cin >> s;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] != '0') {
				keys[s[i] - 'a'] = true;
			}
		}
		q.push({ 0,0 });
		check[0][0] = true;
		while (!q.empty()) {
			auto p = q.front(); q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = p.first + dx[i];
				int ny = p.second + dy[i];
				if (0 <= nx && nx < h + 2 && 0 <= ny && ny < w + 2) {
					if (!check[nx][ny]) {
						char c = map[nx][ny];
						if (c == '.') {
							q.push({ nx,ny });
							check[nx][ny] = true;
						}
						else if (c == '$') {
							ans++;
							q.push({ nx,ny });
							check[nx][ny] = true;
						}
						else if ('a' <= c && c <= 'z') {
							keys[c - 'a'] = true;
							q.push({ nx,ny });
							check[nx][ny] = true;
							while (!al[c - 'a'].empty()) {
								auto n = al[c - 'a'].front(); al[c - 'a'].pop();
								q.push({ n.first,n.second });
								check[n.first][n.second] = true;
							}
						}
						else if ('A' <= c && c <= 'Z') {
							if (keys[c - 'A']) {
								q.push({ nx,ny });
								check[nx][ny] = true;
							}
							else {
								al[c - 'A'].push({ nx,ny });
							}
						}
					}
				}
			}
		}
		cout << ans << "\n";
	}
}