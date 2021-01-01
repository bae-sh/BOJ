#include<iostream>
#include<string>
using namespace std;
int N;
char c;
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N;
	string s; cin >> s;
	c = s[0];
	for (int i = 0; i < N - 1; i++) {
		cin >> s;
		if (c != s[0]) {
			cout << "0\n";
			return 0;
		}
	}
	cout << "1\n";
}