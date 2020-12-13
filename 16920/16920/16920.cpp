#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
int N, M, P;
int S[10];
int map[1000][1000];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
queue<pair<int, int>> q[10];
queue<pair<int, int>> nq[10];
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
				q[s[j] - '0'].push({ i,j });
			}
			else if (s[j] == '#') {
				map[i][j] = -1;
			}
		}
	}
	while (true) {
		for (int k = 1; k <= 9; k++) {
			for (int i = 0; i < 4; i++) {
				
			}
		}
	}
}