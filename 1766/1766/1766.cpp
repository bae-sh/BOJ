#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N, M;
int indegree[32001];
vector<int> v[32001];
priority_queue<int> pq;
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		indegree[b]++;
	}
	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0) {
			pq.push(-i);
		}
	}
	while (!pq.empty()) {
		int cur = -pq.top(); pq.pop();
		for (auto i : v[cur]) {
			indegree[i]--;
			if (indegree[i] == 0) {
				pq.push(-i);
			}
		}
		cout << cur << " ";
	}
}