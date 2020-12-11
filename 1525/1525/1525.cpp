#include<iostream>
#include<map>
#include<queue>
#include<string>
using namespace std;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int start;
map<int, int> m;
queue<int>q;
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	for (int i = 0; i < 9; i++) {
		int t; cin >> t;
		if (t == 0) {
			t = 9;
		}
		start = start * 10 + t;
	}
	m[start] = 0;
	q.push(start);
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		string s = to_string(cur);
		int z = s.find("9");
		int x = z / 3;
		int y = z % 3;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			string next = s;
			if (0 <= nx && nx < 3 && 0 <= ny && ny < 3) {
				swap(next[nx * 3 + ny], next[x * 3 + y]);
				int n = stoi(next);
				if (m.count(n) == 0) {
					m[n] = m[cur] + 1;
					q.push(n);
				}
			}
		}
	}
	if (m.count(123456789) == 0) {
		cout << -1 << "\n";
	}
	else {
		cout << m[123456789] << "\n";
	}
}