#include<iostream>
#include<queue>
#include<vector>
#include<stack>
using namespace std;
int N, K;
vector<int> v[100001];
queue<pair<int, int>> q;//num, cnt
stack<int> ans;
void insert(int next, int cur, int cnt) {
	if (next >= 0 && next <= 100000) {
		if (v[next].empty()) {
			v[next].push_back(cur);
			q.push({ next,cnt + 1 });
		}
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> K;
	v[N].push_back(-1);
	q.push({ N,0 });
	while (1) {
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (cur == K) {
			cout << cnt << "\n";
			int site = cur;
			while (site != -1) {
				ans.push(site);
				site = v[site].front();
			}
			while(!ans.empty()) {
				cout << ans.top() << " ";
				ans.pop();
			}
			break;
		}
		int next = cur - 1;
		insert(next, cur, cnt);
		next = cur * 2;
		insert(next, cur, cnt);
		next = cur + 1;
		insert(next, cur, cnt);
	}
}