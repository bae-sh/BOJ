#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
int N;
int num[10001];//°¹¼ö
int cost[10001];
vector<int> v[10001];
queue<pair<int, int>> job;//left_time,number
int time = 987654321;
int ans;
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		int a, b; cin >> a >> b;
		num[i] = b;
		if (b == 0) {
			job.push({ a,i });
			time = min(time, a);
		}
		else {
			for (int j = 0; j < b; j++) {
				int c; cin >> c;
				v[c].push_back(i);
			}
			cost[i] = a;
		}
	}
	while (!job.empty()) {
		int size = job.size();
		int cTime = time;
		time = 987654321;
		for (int i = 0; i < size; i++) {
			int first = job.front().first;
			int second = job.front().second;
			job.pop();
			first -= cTime;
			if (first == 0) {
				for (int j = 0; j < v[second].size(); j++) {
					int next = v[second][j];
					if (num[next] == 1) {
						job.push({ cost[next],next });
						time = min(time, cost[next]);
					}
					num[next]--;
				}
			}
			else {
				job.push({ first,second });
				time = min(time, first);
			}
		}
		ans +=cTime;

	}
	cout << ans;
}

