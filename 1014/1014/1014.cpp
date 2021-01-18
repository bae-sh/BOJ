#include<iostream>
#include<algorithm>
#include<string>
#include<map>
using namespace std;
int dx[] = { 0,-1,-1 };
int dy[] = { -1,-1,1 };
int c;
int n, m;
char field[10][10];
map<string, int> dp[10];

int dfs(int pos, string s) {
	int ans = 0;
	int x = pos / m;
	int y = pos % m;
	if (pos >= n * m) {
		return 0;
	}
	if (x != 0 && dp[x - 1].count(s) > 0) {
		return dp[x-1][s];
	}
	if (y == 0) {
		s = "";
	}
	string temp = s + field[x][y];
	if (field[x][y] == '.') {
		bool p = true;
		for (int i = 0; i < 3; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (field[nx][ny] == 'O') {//¾ÉÀº°æ¿ì
					p = false; 
					break;
				}
			}
		}
		if (p) {
			temp[y] = field[x][y] = 'O';
			int fir = dfs(pos + 1, temp);
			ans = max(ans, fir + 1);
			if (temp.length() == m) {
				if (dp[x].count(temp) == 0) {
					dp[x].insert({ temp,fir });
				}
				else {
					dp[x][temp] = max(dp[x][temp], fir);
				}
			}
			temp[y] = field[x][y] = '.';
		}
	}
	int sec = dfs(pos + 1, temp);
	ans = max(ans, sec);
	if (temp.length() == m) {
		if (dp[x].count(temp) == 0) {
			dp[x].insert({ temp,sec });
		}
		else {
			dp[x][temp] = max(dp[x][temp], sec);
		}
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> c;
	while (c--) {
		cin >> n >> m;
		for (int i = 0; i < 10; i++) {
			dp[i].clear();
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> field[i][j];
			}
		}

		cout << dfs(0, "") << "\n";
	}
}