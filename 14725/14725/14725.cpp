#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int N, K;
vector<vector<string>> v;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int x; cin >> x;
		vector<string> temp;
		for (int j = 0; j < x; j++) {
			string s; cin >> s;
			temp.push_back(s);
		}
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		int depth = 0;
		if (i != 0) {
			for (int j = 0; j < v[i - 1].size(); j++) {
				if (v[i - 1][j] == v[i][j]) {
					depth++;
				}
				else {
					break;
				}
			}
		}
		int start = depth;
		for (int j = start; j < v[i].size(); j++) {
			for (int k = 0; k < depth; k++) {
				cout << "--";
			}
			cout << v[i][j] << "\n";
			depth++;
		}
	}
}