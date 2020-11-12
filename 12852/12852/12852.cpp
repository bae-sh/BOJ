#include<iostream>
#include<queue>
#include<stack>
using namespace std;
int N;
queue<pair<int, int>> q;
stack<int> st;
int dp[1000001];
void insert(int cur, int next, int cnt) {
	if (dp[next] != 0) {
		return;
	}
	q.push({ next,cnt });
	dp[next] = cur;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N;
	q.push({ N, 0 });
	while (1) {
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (cur == 1) {
			cout << cnt << "\n";
			while (1) {
				if (cur == 0) {
					break;
				}
				st.push(cur);
				cur = dp[cur];
			}
			while(!st.empty()) {
				cout << st.top() << " ";
				st.pop();
			}
			break;
		}
		int next = cur - 1;
		insert(cur, next, cnt + 1);
		if (cur % 3 == 0) {
			next = cur / 3;
			insert(cur, next, cnt + 1);
		}
		if (cur % 2 == 0) {
			next = cur / 2;
			insert(cur, next, cnt + 1);
		}
	}
}