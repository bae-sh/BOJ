#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int n, d;
int ans;
vector<pair<int, int>> v;//right, left
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		v.push_back({ max(a,b),min(a,b) });
	}
	cin >> d;
	sort(v.begin(), v.end());
	priority_queue<int> pq;
	for (int i = 0; i < n; i++) {
		int cur_right = v[i].first;
		pq.push(-v[i].second);
		while (!pq.empty()) {
			int left = -pq.top();
			if (left < cur_right - d) {
				pq.pop();
			}
			else {
				break;
			}
		}
		ans = max(ans, (int)pq.size());
	}
	cout << ans << "\n";
}