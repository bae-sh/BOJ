#include<iostream>
#include<algorithm>
#define INF 987654321
using namespace std;
int n;
int red[1001][3];//red green blue
int green[1001][3];
int blue[1001][3];
int a, b, c;
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	cin >> a >> b >> c;
	red[1][0] = a; red[1][1] = INF; red[1][2] = INF;
	green[1][1] = b; green[1][0] = INF; green[1][2] = INF;
	blue[1][2] = c; blue[1][0] = INF; blue[1][1] = INF;
	for (int i = 2; i <= n - 1; i++) {
		cin >> a >> b >> c;
		red[i][0] = min(red[i - 1][1], red[i - 1][2]) + a;
		red[i][1] = min(red[i - 1][0], red[i - 1][2]) + b;
		red[i][2] = min(red[i - 1][0], red[i - 1][1]) + c;
		green[i][0] = min(green[i - 1][1], green[i - 1][2]) + a;
		green[i][1] = min(green[i - 1][0], green[i - 1][2]) + b;
		green[i][2] = min(green[i - 1][0], green[i - 1][1]) + c;
		blue[i][0] = min(blue[i - 1][1], blue[i - 1][2]) + a;
		blue[i][1] = min(blue[i - 1][0], blue[i - 1][2]) + b;
		blue[i][2] = min(blue[i - 1][0], blue[i - 1][1]) + c;
	}
	cin >> a >> b >> c;
	int ans = INF;
	red[n][1] = min(red[n - 1][0], red[n - 1][2]) + b;
	ans = min(ans, red[n][1]);
	red[n][2] = min(red[n - 1][0], red[n - 1][1]) + c;
	ans = min(ans, red[n][2]);
	green[n][0] = min(green[n - 1][1], green[n - 1][2]) + a;
	ans = min(ans, green[n][0]);
	green[n][2] = min(green[n - 1][0], green[n - 1][1]) + c;
	ans = min(ans, green[n][2]);
	blue[n][1] = min(blue[n - 1][0], blue[n - 1][2]) + b;
	ans = min(ans, blue[n][1]);
	blue[n][0] = min(blue[n - 1][1], blue[n - 1][2]) + a;
	ans = min(ans, blue[n][0]);
	cout << ans;
}