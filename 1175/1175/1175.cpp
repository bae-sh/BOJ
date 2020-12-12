#include<iostream>
#include<queue>
#include<algorithm>
#include<string.h>
using namespace std;
int N, M;
int map[51][51];
int dp[51][51][4][4];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
vector<pair<int,int>> v;
queue < pair<pair<pair<int, int>, int>, int>> q;//x,y,way,cnt
int main() {
	ios::sync_with_stdio(false); cout.tie(0); cin.tie(0);
	cin >> N >> M;

	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < N; i++) {
		string s; cin >> s;
		for (int j = 0; j < M; j++) {
			if (s[j] == 'S') {
				for (int k = 0; k < 4; k++) {
					dp[i][j][k][0] = 0;
					q.push({ {{i,j},k},0 });
				}
			}
			else if (s[j] == 'C') {
				v.push_back({ i,j });
			}
			else if (s[j] == '#') {
				map[i][j] = -1;
			}
		}
	}

	while (!q.empty()) {
		int x = q.front().first.first.first;
		int y = q.front().first.first.second;
		int way = q.front().first.second;
		int cnt = q.front().second; q.pop();

		for (int i = 0; i < 4; i++) {
			if (i != way) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				int ncnt = cnt;
				if (0 <= nx && nx < N && 0 <= ny && ny < M && map[nx][ny] != -1) {
					for (int j = 0; j < 2; j++) {
						if (nx == v[j].first && ny == v[j].second) {
							ncnt |= j + 1;
						}
					}
					if (dp[nx][ny][i][ncnt] == -1) {
						dp[nx][ny][i][ncnt] = dp[x][y][way][cnt] + 1;
						if (ncnt == 3) {
							cout << dp[nx][ny][i][ncnt];
							return 0;
						}
						else {
							q.push({ {{nx,ny},i},ncnt });
						}
					}
				}
			}
		}
	}
	cout << "-1\n";
}