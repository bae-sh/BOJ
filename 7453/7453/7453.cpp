#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
vector<long long> v[4];
vector<long long> ab;
long long ans;
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			long long temp; cin >> temp;
			v[j].push_back(temp);
		}
	}

	// a b / c d
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			long long temp = v[0][i] + v[1][j];
			ab.push_back(temp);
		}
	}
	sort(ab.begin(), ab.end());
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			long long temp = v[2][i] + v[3][j];
			long long up = upper_bound(ab.begin(), ab.end(), -temp) - ab.begin();
			long long down = lower_bound(ab.begin(), ab.end(), -temp) - ab.begin();
			ans += up - down;

		}
	}
	cout << ans;
}