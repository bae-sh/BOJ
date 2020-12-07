#include<iostream>
#include<vector>
#include<string>

using namespace std;
int N, S, E, T;
int map[11][11];
int search(int pos,int num) {

}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> S >> E >> T;
	for (int i = 1; i <= N; i++) {
		string s; cin >> s;
		for (int j = 0; j < s.length(); j++) {
			map[i][j] = s[j] - '0';
		}
	}

}