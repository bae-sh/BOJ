#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
int n;
vector<int> v;
stack<int> st;
int road[500001];//b>a
int p[500001];
int cnt = 1;
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		road[a] = b;
	}
	for (int i = 1; i <= 500000; i++) {
		if (road[i] == 0) {
			continue;
		}
		int next = road[i];
		if (v.empty() || v.back() < next) {
			v.push_back(next);
			p[i] = cnt; cnt++;
		}
		else {
			int pos = lower_bound(v.begin(), v.end(), next)-v.begin();
			v[pos] = next;
			p[i] = pos + 1;
		}
	}
	for (int i = 500000; i >= 0; i--) {
		if (p[i] == cnt - 1) {
			cnt--;
		}
		else if (p[i] != 0) {
			st.push(i);
		}
	}
	int size = st.size();
	cout << size << "\n";
	for (int i = 0; i < size; i++) {
		cout << st.top() << "\n"; st.pop();
	}
}