#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<string.h>
using namespace std;
int N, M;
int scc[20001];
bool check[20001];
vector<int> v[20001];
vector<int> rev[20001];
stack<int> st;
int idx;
void go(int x) {
	scc[x] = idx;
	for (int i : rev[x]) {
		if (scc[i] != 0) continue;
		go(i);
	}
}
void dfs(int x) {
	check[x] = true;
	for (int i : v[x]) {
		if (check[i]) continue;
		dfs(i);
	}
	st.push(x);
}
int f(int x) {
	return (x <= N) ? x + N : x - N;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		if (a < 0) a = -a + N;
		if (b < 0) b = -b + N;
		v[f(a)].push_back(b);
		rev[b].push_back(f(a));
		v[f(b)].push_back(a);
		rev[a].push_back(f(b));
	}
	for (int i = 1; i <= N * 2; i++) {
		if (check[i]) continue;
		dfs(i);
	}
	while (!st.empty()) {
		int cur = st.top(); st.pop();
		if (scc[cur]) continue;
		idx++;
		go(cur);
	}
	for (int i = 1; i <= N; i++) {
		if (scc[i] == scc[i + N]) {
			cout << "0\n";
			return 0;
		}
	}
	cout << "1\n";
}