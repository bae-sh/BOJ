#include<iostream>
using namespace std;

long long a, b;
int ans = -1;
void dfs(long long cur,int cnt) {
	if (cur > b || ans != -1) {
		return;
	}

	if (cur == b) {
		ans = cnt;
	}
	else {
		dfs(cur * 10 + 1, cnt + 1);
		dfs(cur * 2, cnt + 1);
	}

}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> a >> b;
	dfs(a, 1);
	cout << ans << "\n";
}