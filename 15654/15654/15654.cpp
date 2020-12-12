#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int N, M;
vector<int> v;
vector<int> ans;
bool s[8];

void DFS(int cnt) {
	if (cnt == M) {
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i]<<" ";
		}
		cout << "\n";
		return;
	}
	else {
		for (int i = 0; i < N; i++) {
			if (s[i] == true) continue;
			s[i] = true;
			ans.push_back(v[i]);
			DFS(cnt + 1);
			s[i] = false;
			ans.pop_back();
		}
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int a; cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	DFS(0);
}