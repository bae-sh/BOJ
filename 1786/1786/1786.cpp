#include<iostream>
#include<string>
#include<vector>
using namespace std;
string T, P;
vector<int> getPi(string p) {
	int j = 0;
	vector<int> pi(p.size(), 0);
	for (int i = 1; i < p.size(); i++) {
		while (j > 0 && p[i] != p[j]) {
			j = pi[j - 1];
		}
		if (p[i] == p[j]) {
			pi[i] = ++j;
		}
	}
	return pi;
}
vector<int> kmp() {
	int j = 0;
	auto pi = getPi(P);
	vector<int> ret;
	for (int i = 0; i < T.size(); i++) {
		while (j > 0 && T[i] != P[j]) {
			j = pi[j - 1];
		}
		if (T[i] == P[j]) {
			if (j == P.size() - 1) {
				ret.push_back(i - P.size() + 1);
				j = pi[j];
			}
			else {
				j++;
			}
		}
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	getline(cin, T);
	getline(cin, P);
	vector<int> ans = kmp();
	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] + 1 << " ";
	}
}