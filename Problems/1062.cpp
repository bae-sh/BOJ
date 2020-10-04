#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int N, K;
int ans;
string st[50];
int alpa[26];//a,n,t,i,c,는 무조껀 들어가야함
vector<int>order;
int p[21];

int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> st[i];
	}
	for (int i = 0; i < 26; i++) {
		if (i != 'a' - 'a' && i != 'n' - 'a' && i != 't' - 'a' && i != 'i' - 'a' && i != 'c' - 'a') {
			order.push_back(i);
		}
		else {
			alpa[i] = 1;
		}
	}
	for (int i = 0; i < K - 5; i++) {
		p[i] = 1;
	}
	if (K < 5) {
		cout << 0;
	}
	else {
		do {
			int cnt = 0;
			for (int i = 0; i < 21; i++) {
				if (p[i] == 1) {
					alpa[order[i]] = 1;
				}
			}
			for (int i = 0; i < N; i++) {
				string s = st[i];
				bool all = true;
				for (int j = 0; j < s.length(); j++) {
					if (!alpa[s[j] - 'a']) {
						all = false;
						break;
					}
				}
				if (all) {
					cnt++;
				}
			}
			ans = max(ans, cnt);
			for (int i = 0; i < 21; i++) {
				if (p[i] == 1) {
					alpa[order[i]] = 0;
				}
			}
		} while (prev_permutation(p, p+21));
		cout << ans;
	}
}