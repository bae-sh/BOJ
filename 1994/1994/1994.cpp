#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
vector<int> v;
map<int, int> m[2000];
int N;
int ans = 1;
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int x; cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < i; j++) {
			int p = v[i] - v[j];
			if (m[i].count(p) == 0) {
				if (m[j].count(p) == 0) {
					m[i].insert({ p,2 });
				}
				else {
					m[i].insert({ p,m[j][p] + 1 });
				}
			}
			else {
				if (m[j].count(p) == 1) {
					int value = max(m[j][p] + 1, m[i][p]);
					m[i][p] = value;
				}
			}
			ans = max(ans, m[i][p]);
		}
	}
	cout << ans << "\n";
}