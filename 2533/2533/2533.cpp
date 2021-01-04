#include<iostream>
#include<vector>
using namespace std;
int N;
int ans;
vector<int> v[1000001];
bool check[1000001];
bool early[1000001];
void bfs(int cur,int parent) {
	for (int i = 0; i < v[cur].size(); i++) {
		int next = v[cur][i];
		if (!check[next]) {
			check[next] = true;
			bfs(next, cur);
		}
	}
	if (!early[cur]&&!early[parent]) {
		early[parent] = true;
		ans++;
		if (parent == 0) {
			ans--;
		}
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	check[1] = true;
	bfs(1, 0);
	cout << ans << "\n";
}