#include<iostream>
#include<queue>
using namespace std;
int T, L, x, y, Ax, Ay;
int dx[] = { -2,-1,1,2,2,1,-1,-2 };
int dy[] = { 1,2,2,1,-1,-2,-2,-1 };
int main() {
	cin >> T;
	while (T-- > 0) {
		int board[300][300] = {0};
		cin >> L >> x >> y >> Ax >> Ay;
		queue<pair<int, int>> q;
		q.push(make_pair(x, y));
		while (!q.empty()) {
			int curX = q.front().first;
			int curY = q.front().second;
			if (curX == Ax && curY == Ay) {
				break;
			}
			q.pop();

			for (int i = 0; i < 8; i++) {
				int nx = curX + dx[i];
				int ny = curY + dy[i];
				if (0 <= nx && nx < L && 0 <= ny && ny < L) {
					if (!board[nx][ny]) {
						board[nx][ny] = board[curX][curY] + 1;
						q.push(make_pair(nx, ny));
					}
				}
			}
		}
		cout << board[Ax][Ay] << endl ;
	}
}