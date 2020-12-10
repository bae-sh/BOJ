#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
vector<int> tsort(vector<vector<int>>& g) {
	int n = g.size();
	vector<int> ind(n);
	for (int i = 0; i < n; i++) {
		for (int j : g[i]) {
			ind[j]++;
		}
	}
	vector<int>order;
	queue<int> q;
	for (int i = 0; i < n; i++) {
		if (ind[i] == 0) {
			q.push(i);
			order.push_back(i);
		}
	}
	while (!q.empty()) {
		int x = q.front(); q.pop();
		for (int y : g[x]) {
			ind[y]--;
			if (ind[y] == 0) {
				q.push(y);
				order.push_back(y);
			}
		}
	}
	return order;
}
bool go(int k, vector<int>& b, vector<int>& order, vector<vector<int>>& g) {
	int n = b.size();
	vector<int> a(n);
	for (int x : order) {
		a[x]= 2000000000;
		for (int y : g[x]) {
			a[x] = min(a[x], a[y] - 1);
		}
		if (x < k) {
			if (b[x] > a[x]) return false;
			a[x] = b[x];
		}
		if (a[x] <= 0) {//Á¶°Ç x
			return false;
		}
		for (int i = 0; i < n; i++) {
			if (a[i] > b[i]) return true;
			if (a[i] < b[i]) return false;
		}
	}
	return true;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n);
	vector<vector<int>> gr(n);
	vector<int> b(n);
	for (int i = 0; i <= n; i++) {
		cin >> b[i];
	}
	while (m--) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		g[u].push_back(v);
		gr[v].push_back(u);
	}
	vector<int> order;
	order = tsort(g);
	if (order.size() != n) {
		cout << -1 << "\n";
		return 0;
	}
	int ans = 0;
	int left = 0;
	int right = n - 1;
	reverse(order.begin(), order.end());
	while (left <= right) {
		int mid = (left + right) / 2;
		if (go(mid, b, order, g)) {
			left = mid + 1;
			ans = max(ans, mid);
		}
		else {
			right = mid - 1;
		}
	}

}