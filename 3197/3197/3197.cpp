#include<iostream>
#include<queue>
#include<string.h>
#include<algorithm>
using namespace std;
int R, C;
int map[1500][1500];
bool wcheck[1500][1500];
bool scheck[1500][1500];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
vector<pair<int, int>> v;

queue<pair<int, int>> swan, water, nswan, nwater;//¹éÁ¶
int t;
int main() {
	ios::sync_with_stdio(false); cout.tie(0); cin.tie(0);

	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		string s; cin >> s;
		for (int j = 0; j < C; j++) {
			if (s[j] == '.') {
				water.push({ i,j });
				wcheck[i][j] = true;
			}
			else if (s[j] == 'X') {
				map[i][j] = 1;
			}
			else {
				water.push({ i,j });
				wcheck[i][j] = true;
				v.push_back({ i, j });
			}
		}
	}
	swan.push({ v[0].first,v[0].second });
	scheck[v[0].first][v[0].second] = true;
	while (true) {
		while (!water.empty()) {
			auto p = water.front(); water.pop();
			map[p.first][p.second] = 0;
			for (int i = 0; i < 4; i++) {
				int nx = p.first + dx[i];
				int ny = p.second + dy[i];
				if (0 <= nx && nx < R && 0 <= ny && ny < C) {
					if (map[nx][ny] == 0 && !wcheck[nx][ny]) {
						water.push({ nx,ny });
						wcheck[nx][ny] = true;
					}
					else if (map[nx][ny] == 1 && !wcheck[nx][ny]) {
						nwater.push({ nx,ny });
						wcheck[nx][ny] = true;
					}
				}
			}
		}
		while (!swan.empty()) {
			auto p = swan.front(); swan.pop();
			for (int i = 0; i < 4; i++) {
				int nx = p.first + dx[i];
				int ny = p.second + dy[i];
				if (0 <= nx && nx < R && 0 <= ny && ny < C) {
					if (map[nx][ny] == 0 && !scheck[nx][ny]) {
						swan.push({ nx,ny });
						scheck[nx][ny] = true;
					}
					else if (map[nx][ny] == 1 && !scheck[nx][ny]) {
						nswan.push({ nx,ny });
						scheck[nx][ny] = true;
					}
				}
			}
		}
		if (scheck[v[1].first][v[1].second]) {
			cout << t;
			break;
		}
		t++;
		water = nwater;
		swan = nswan;
		nwater = queue<pair<int, int>>();
		nswan = queue<pair<int, int>>();
	}
}