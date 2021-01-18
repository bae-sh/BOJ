#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;
int dx[] = { -1,0,0,1 };
int dy[] = { 0,-1,1,0 };
int N;
int map[20][20];
bool check[20][20];
pair<int, int> pos;
int fish_num[7];
int fish_size = 2;
int ate_fish;
int min_time;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				pos = { i,j };
				map[i][j] = 0;
			}
			else if (map[i][j] != 0) {
				fish_num[map[i][j]] ++;
			}

		}
	}
	
	queue<pair<int, pair<int, int>>> q;
	queue<pair<int, pair<int, int>>> temp;
	vector<pair<int, int>> ate;
	q.push({ 0,pos });
	check[pos.first][pos.second] = true;
	while (!q.empty()) {
		int t = q.front().first;
		auto cur = q.front().second; q.pop();
		
		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if (0 <= nx && nx < N && 0 <= ny && ny < N) {
				if (!check[nx][ny]) {
					if (map[nx][ny] == 0 || map[nx][ny] == fish_size) {
						check[nx][ny] = true;
						q.push({ t + 1,{nx,ny} });
					}
					else if (map[nx][ny] <= fish_size) {
						ate.push_back({ nx,ny });
					}
				}
			}
		}
		if (q.empty()||q.front().first != t) {
			if (!ate.empty()) {
				sort(ate.begin(), ate.end());
				auto p = ate[0];
				ate_fish++; fish_num[map[p.first][p.second]]--;
				map[p.first][p.second] = 0;
				if (ate_fish == fish_size) {
					fish_size++;
					ate_fish = 0;
				}
				memset(check, 0, sizeof(check));
				check[p.first][p.second] = true;
				ate.clear();
				q = temp;
				min_time = t + 1;
				q.push({ t + 1, { p.first,p.second } });
			}
		}
		if (q.empty()) {
			cout << min_time << "\n";
			break;
		}
	}
}