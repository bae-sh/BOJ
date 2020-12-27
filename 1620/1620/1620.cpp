#include<iostream>
#include<map>
#include<string>
using namespace std;
int N, M;
string a[100001];
map<string, int> b;
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		string s; cin >> s;
		a[i] = s;
		b[s] = i;
	}
	while (M--) {
		string s; cin >> s;
		if (b.count(s) == 0) {
			cout << a[stoi(s)] << "\n";
		}
		else {
			cout << b[s] << "\n";
		}
	}
}