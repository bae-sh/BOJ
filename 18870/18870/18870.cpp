#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<int, int>> v;
int num[1000001];
bool check[1000001];
int N, cnt, temp;
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		int x; cin >> x;
		v.push_back({ x,i });
	}
	sort(v.begin(), v.end());
	for (int i = 1; i < v.size(); i++) {
		int pre = v[i - 1].second;
		int cur = v[i].second;
		if (v[i - 1].first == v[i].first) {
			num[cur] = num[pre];
		}
		else {
			num[cur] = num[pre] + 1;
		}
	}
	for (int i = 1; i <= N; i++) {
		cout << num[i] << " ";
	}
}