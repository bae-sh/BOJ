#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
int n, m;;
int order[8];
int num[8];
void dfs(int depth,int start) {
	if (depth == m) {
		for (int i = 0; i < m; i++) {
			cout << num[i] << " ";
		}
		cout << "\n";
		return;
	}
	int before = 0;
	for (int i = start; i < n; i++) {
		if (before == order[i]) continue;
		num[depth] = order[i];
		dfs(depth + 1, i);
		before = order[i];
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> order[i];
	}
	sort(order, order + n);
	dfs(0, 0);
}