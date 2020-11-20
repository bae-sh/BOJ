#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<cstring>
#define INF 987654321
using namespace std;
int n, m, start, goal;
int Dist[1001];
vector<pair<int, int>> v[1001];
priority_queue<pair<int, int>> pq;
stack<int> st;
int dp[1001];
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		v[a].push_back({ b,c });
	}
	cin >> start >> goal;

	for (int i = 0; i < 1001; i++) {
		Dist[i] = INF;
	}
	Dist[start] = 0;
	pq.push({ 0,start });
	//다익스트라
	while (!pq.empty()) {
		int cur = pq.top().second;
		int cCost = -pq.top().first;
		pq.pop();
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i].first;
			int nCost = cCost + v[cur][i].second;
			if (Dist[next] > nCost) {
				pq.push({ -nCost, next});
				Dist[next] = nCost;
				dp[next] = cur;
			}

		}
	}
	int cur = goal;
	while (1) {
		st.push(cur);
		if (cur == start) {
			break;
		}
		cur = dp[cur];
	}
	cout << Dist[goal] << "\n" << st.size() << "\n";
	int size = st.size();
	for (int i = 0; i < size; i++) {
		cout << st.top() << " "; st.pop();
	}
}