#include<iostream>
#include<map>
#include<string>
#include<vector>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int n;
		cin >> n;

		map<string, int> firstPublicKey;
		for (int i = 0; i < n; i++) {
			string key;
			cin >> key;

			firstPublicKey[key] = i;
		}

		map<int, int>orders;
		for (int i = 0; i < n; i++) {
			string key;
			cin >> key;

			orders[firstPublicKey[key]] = i;
		}
		vector<string> password(n);
		for (int i = 0; i < n; i++) {
			cin >> password[i];
		}
		for (int i = 0; i < n; i++) {
			cout << password[orders[i]] << " ";
		}
		cout << "\n";
	}
}