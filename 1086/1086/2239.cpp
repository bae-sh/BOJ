#include<iostream>
#include<cstring>
using namespace std;
int s[9][9];
int cnt;//0ÀÇ °¹¼ö
void prt() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << s[i][j];
		}
		cout << "\n";
	}
}

void sol(int x,int y,int count) {
	if (count == cnt) {
		prt();
		exit(0);
	}

	int nx = x; int ny = y + 1;
	if (ny > 8) {
		nx++; ny = 0;
	}

	if (s[x][y] == 0) {
		int possible[10] = { 0, };
		for (int i = 0; i < 9; i++) {
			int num = s[x][i];
			possible[num] = 1;
			num = s[i][y];
			possible[num] = 1;
		}
		int dx = (x / 3) * 3; int dy = (y / 3) * 3;
		for (int i = dx; i < dx + 3; i++) {
			for (int j = dy; j < dy + 3; j++) {
				int num = s[i][j];
				possible[num] = 1;
			}
		}
		for (int i = 1; i <= 9; i++) {
			if (possible[i] == 0) {
				s[x][y] = i;
				sol(nx, ny, count + 1);
				s[x][y] = 0;
			}
		}
	}
	else {
		sol(nx, ny, count);
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	for (int i = 0; i < 9; i++) {
		char c[12]; cin >> c;
		for (int j = 0; j < 9; j++) {
			s[i][j] = c[j] - '0';
			if (s[i][j] == 0) {
				cnt++;
			}
		}
	}
	sol(0, 0, 0);
}