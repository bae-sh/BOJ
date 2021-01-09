#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int N, M, K;
vector<int> v;
vector<bool> checked;
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		int x; cin >> x;
		v.push_back(x);
		checked.push_back(false);
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < K; i++) {
		int x; cin >> x;
		int index = upper_bound(v.begin(), v.end(), x) - v.begin();
		while (checked[index]) index++;
		checked[index] = true;
		cout << v[index] << "\n";
	}
}