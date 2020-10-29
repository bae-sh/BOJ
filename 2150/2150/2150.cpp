#include<iostream>
#include<vector>
#include<cstring>
#include<stack>
#include<algorithm>
using namespace std;
int V, E, cnt;
bool visited[10001];
vector<int> e[10001];//right way
vector<int> rev[10001];//reverse way
stack<int> st;
vector<int> ans[10001];
void dfs(int a) {
	visited[a] = true;
	for (auto i : e[a]) {
		if (!visited[i]) dfs(i);
	}
	st.push(a);
}
void redfs(int a, int cnt) {
	visited[a] = true;
	for (auto i : rev[a]) {
		if (!visited[i]) redfs(i, cnt);
	}
	ans[cnt].push_back(a);
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int a, b; cin >> a >> b;
		e[a].push_back(b);
		rev[b].push_back(a);
	}

	for (int i = 1; i <= V; i++) {
		if (!visited[i]) dfs(i);
	}
	memset(visited, false, sizeof(visited));

	while (!st.empty()) {
		int cur = st.top(); st.pop();
		if (!visited[cur]) redfs(cur, cnt++);
	}
	vector<pair<int, int>> v;
	for (int i = 0; i < cnt; i++) {
		sort(ans[i].begin(), ans[i].end());
		v.push_back({ ans[i][0],i });
	}
	sort(v.begin(), v.end());
	cout << cnt << "\n";
	for (int i = 0; i < cnt; i++) {
		int index = v[i].second;
		for (auto a : ans[index]) {
			cout << a << " ";
		}
		cout << "-1\n";
	}
}