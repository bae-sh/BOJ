#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;
int n, m;
int ans;
vector<int> v[51];

void dfs(int depth,int p[],int sum) {
	if (depth == m) {
		ans = max(ans, sum);
		return;
	}
	int temp[51];
	int check = 0;
	memcpy(temp, p,sizeof(temp));
	for (int i = 0; i < v[depth].size(); i++) {
		int& num = v[depth][i];
		if (p[num] == 0) {
			continue;
		}
		else if (p[num] == 1) {
			if (check == 2) {
				return;
			}
			else {
				check = 1;
			}
		}
		else if (p[num] == 2) {
			if (check == 1) {
				return;
			}
			else {
				check = 2;
			}
		}
	}
	if (check == 0) {
		for (int i = 0; i < v[depth].size(); i++) {
			temp[v[depth][i]] = 1;
		}
		dfs(depth + 1, temp, sum + 1);
		memcpy(temp, p, sizeof(temp));
		for (int i = 0; i < v[depth].size(); i++) {
			temp[v[depth][i]] = 2;
		}
		dfs(depth + 1, temp, sum);
	}
	else if (check == 1) {
		for (int i = 0; i < v[depth].size(); i++) {
			temp[v[depth][i]] = 1;
		}
		dfs(depth + 1, temp, sum + 1);
	}
	else {
		for (int i = 0; i < v[depth].size(); i++) {
			temp[v[depth][i]] = 2;
		}
		dfs(depth + 1, temp, sum);
	}
	return;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	int a; cin >> a;
	int p[51];//진실 2 과장 1 듣지x 0
	memset(p, 0, sizeof(p));
	for (int i = 0; i < a; i++) {
		int x; cin >> x;
		p[x] = 2;
	}
	for (int i = 0; i < m; i++) {
		int x; cin >> x;
		for (int j = 0; j < x; j++) {
			int y; cin >> y;
			v[i].push_back(y);
		}
	}
	dfs(0, p, 0);
	cout << ans << "\n";
}