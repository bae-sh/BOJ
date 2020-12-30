#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
long long ans;
vector<pair<int, int>> v;//가치 , 무게
multiset<int> bag;
int pos;//보석 위치
int N, K;
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int a, b; cin >> a >> b;
		v.push_back({ -b,a });
	}
	for (int i = 0; i < K; i++) {
		int a; cin >> a;
		bag.insert(a);

	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		auto iter = bag.lower_bound(v[i].second);

		if (iter == bag.end()) {
			continue;
		}
		else {
			ans += (-v[i].first);
			bag.erase(iter);
		}
	}
	cout << ans << "\n";
}