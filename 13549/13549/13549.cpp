#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

priority_queue<pair<int, int>> q;//cost,pos
bool dp[100001];

int N, K;
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> K;
	q.push({ 0,N });
	while (!q.empty()) {
		int pos = q.top().second; 
		int cost = -q.top().first; q.pop();
		if (dp[pos]) continue;
		if (pos == K) {
			cout << cost;
			break;
		}
		dp[pos] = true;
		int next = pos * 2;
		if (next <= 100000 && !dp[next]) {
			q.push({ -cost,next });
		}
		next = pos + 1;
		if (next <= 100000 && !dp[next]) {
			q.push({ -(cost + 1),next });
		}
		next = pos - 1;
		if (next >= 0&& !dp[next]) {
			q.push({ -(cost + 1),next });
		}
	}
}
