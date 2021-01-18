#include<iostream>
#include<string>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	while (true) {
		string a; cin >> a;
		if (a == "0") {
			break;
		}
		else {
			int len = a.size();
			bool p = true;
			for (int i = 0; i <= (len / 2) - 1; i++) {
				if (a[i] != a[len - i - 1]) {
					p = false;
				}
			}
			if (p) {
				cout << "yes\n";
			}
			else {
				cout << "no\n";
			}
		}
	}
}