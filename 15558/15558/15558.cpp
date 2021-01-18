#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
int N, K;
int road[300201][2];
bool check[300201][2];
int timer;
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> K;
	for (int i = 0; i < 2; i++) {
		string s; cin >> s;
		for (int j = 0; j < N; j++) {
			road[j + 1][i] = s[j] - '0';
		}
	}
	queue<pair<pair<int, int>,int>> q;
	q.push({ { 1,0 },0 });
	while (!q.empty()) {
		auto p = q.front(); q.pop();
		for (auto i : { make_pair(p.first.first + 1,p.first.second),make_pair(p.first.first - 1,p.first.second),make_pair(p.first.first + K,(p.first.second + 1) % 2) }) {
			int nx = i.first;
			int ny = i.second;
			if (nx > N) {
				cout << 1 << "\n";
				return 0;
			}
			if (0 < nx && nx < 300201) {
				if (!check[nx][ny] && nx > p.second + 1 && road[nx][ny] == 1) {
					check[nx][ny] = true;
					q.push({ { nx,ny }, p.second + 1 });
				}
			}
		}
	}
	cout << 0 << "\n";
}