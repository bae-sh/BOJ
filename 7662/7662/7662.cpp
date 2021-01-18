#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
int T, k;
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> T;
	while (T--) {
		multiset<int> s;
		cin >> k;
		for (int i = 0; i < k; i++) {
			char c; int a; cin >> c >> a;
			if (c == 'I') {
				s.insert(a);
			}
			else {
				if (s.empty()) {
					continue;
				}
				if (a == 1) {
					auto iter = s.end();
					iter --;
					s.erase(iter);
				}
				else {
					s.erase(s.begin());
				}
			}
		}
		if (s.empty()) {
			cout << "EMPTY" << "\n";
		}
		else {
			auto iter = s.end();
			iter--;
			cout << *iter << " " << *s.begin() << "\n";
		}
	}
	
}