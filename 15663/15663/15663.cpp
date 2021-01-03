#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
int N, M;
vector<int> v;
vector<int> t;
bool num[8];
map<string, int> m;
void go(int depth,vector<int> order) {
	if (depth == M) {
		string s = "";
		for (int i = 0; i < order.size(); i++) {
			s += to_string(v[order[i]]) + " ";
		}
		if (m.count(s) == 0) {
			cout << s << "\n";
			m.insert({s, 1});
		}
		return;
	}
	for (int i = 0; i < N; i++) {
		if (!num[i]) {
			num[i] = true;
			order.push_back(i);
			go(depth + 1, order);
			num[i] = false;
			order.erase(order.end() - 1);
		}
	}
	return;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int x; cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	go(0, t);
}