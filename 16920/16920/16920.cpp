#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
int N, M, P;
int S[10];
int map[1000][1000];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
queue<pair<pair<int, int>,int>> q[10];
queue<pair<pair<int, int>,int>> nq[10];
int ans[26];
int main() {
	ios::sync_with_stdio(false); cout.tie(0); cin.tie(0);

	cin >> N >> M >> P;
	for (int i = 1; i <= P; i++) {
		cin >> S[i];
	}
	for (int i = 0; i < N; i++) {
		string s; cin >> s;
		for (int j = 0; j < M; j++) {
			if ('1' <= s[j] && s[j] <= '9') {
				map[i][j] = s[j] - '0';
				q[s[j] - '0'].push({ { i,j },S[s[j] - '0'] });
			}
			else if (s[j] == '#') {
				map[i][j] = -1;
			}
		}
	}
	while (true) {
		bool full = true;
		for (int k = 1; k <= P; k++) {
			while (!q[k].empty()) {
				auto p = q[k].front(); q[k].pop();
				for (int i = 0; i < 4; i++) {
					int nx = p.first.first + dx[i];
					int ny = p.first.second + dy[i];
					int ncost = p.second;
					if (0 <= nx && nx < N && 0 <= ny && ny < M) {
						if (map[nx][ny] == 0) {
							map[nx][ny] = k;
							full = false;
							if (ncost == 1) {
								nq[k].push({ {nx,ny},S[k] });
							}
							else {
								q[k].push({ {nx,ny},ncost - 1 });
							}
						}
					}

				}
			}
			q[k] = nq[k];
			nq[k] = queue <pair<pair<int, int>,int>>();
		}
		if (full) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					ans[map[i][j]]++;
				}
			}
			break;
		}
	}
	for (int i = 1; i <= P; i++) {
		cout << ans[i] << " ";
	}
}