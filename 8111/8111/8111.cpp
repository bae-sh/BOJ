#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> from(n, -1);
		vector<bool> check(n, false);
		vector<int> how(n, -1);
		queue<int> q;
		q.push(1%n);
		check[1%n] = true;
		how[1%n] = 1;
		while (!q.empty()) {
			int now = q.front(); q.pop();
			for (int i = 0; i <= 1; i++) {
				int next = (now * 10 + i) % n;
				if (!check[next]) {
					check[next] = true;
					from[next] = now;
					how[next] = i;
					q.push(next);
				}
			}
		}
		if (!check[0]) {
			cout << "BRAK" << "\n";
		}
		else {
			string ans = "";
			for (int i = 0; i != -1; i = from[i]) {
				ans += to_string(how[i]);
			}
			reverse(ans.begin(), ans.end());
			cout << ans << "\n";
		}
	}
}