#include<iostream>
#include<algorithm>
#include<queue>
#include<string.h>
using namespace std;

int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int N, M, time;
int map[100][100];
int cheese;
void outAir(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x,y });
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if (0 <= nx && nx < N && 0 <= ny && ny < M) {
				if (map[nx][ny] == 0) {
					map[nx][ny] = -1;
					q.push({ nx,ny });
				}
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int a; cin >> a;
			map[i][j] = a;
			if (a == 1) cheese++;
		}
	}
	outAir(0, 0);
	while (cheese) {
		time++;
		int temp[100][100];
		memcpy(temp, map, sizeof(temp));
		queue<pair<int, int>> delcheese;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 1) {
					int cnt = 0;
					for (int k = 0; k < 4; k++) {
						int nx = i + dx[k];
						int ny = j + dy[k];
						if (0 <= nx && nx < N && 0 <= ny && ny < M) {
							if (map[nx][ny] == -1) {
								cnt++;
							}
						}
					}
					if (cnt >= 2) {
						temp[i][j] = -1;
						delcheese.push({ i,j });
						cheese--;
					}
				}
			}
		}
		memcpy(map, temp, sizeof(map));
		while (!delcheese.empty()) {
			auto cur = delcheese.front(); delcheese.pop();
			outAir(cur.first, cur.second);
		}
	}
	cout << time << "\n";
}