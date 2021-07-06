#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
vector<pair<pair<int, int>,int>> order;
int ball[200001];
int ans[200001];
int N;
vector<pair<int, int>> update;
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int c, s; cin >> c >> s;
		order.push_back({ { s,c },i });
	}
	sort(order.begin(), order.end());

	for (int i = 0; i < N; i++) {
		int c = order[i].first.second;
		int s = order[i].first.first;
		int idx = order[i].second;
		ans[idx] = ball[0] - ball[c];
		if (i + 1 != N && order[i + 1].first.first == s) {
			update.push_back({ s,c });
		}
		else {
			ball[c] += s;
			ball[0] += s;
			for (int j = 0; j < update.size(); j++) {
				c = update[j].second;
				s = update[j].first;
				ball[c] += s;
				ball[0] += s;
			}
			update.clear();
		}
	}

	for (int i = 0; i < N; i++) {
		cout << ans[i] << "\n";
	}
}