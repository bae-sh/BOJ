#include<iostream>
#include<queue>
#include<vector>

using namespace std;
int N, M, ans;
vector<pair<int, int>> v[1001];//to,cost
priority_queue<pair<int, int>> pq;
bool used[1001];
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//prim
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c; cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	pq.push({ 0,1 });
	while (!pq.empty()) {
		int from = pq.top().second; 
		int cost = -pq.top().first; pq.pop();
		if (used[from]) {
			continue;
		}
		ans += cost;
		used[from] = true;
		for (auto i : v[from]) {
			if (!used[i.first]) {
				pq.push({ -i.second,i.first });
			}
		}
	}
	cout << ans;
}