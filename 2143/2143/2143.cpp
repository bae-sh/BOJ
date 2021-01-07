#include<iostream>
#include<map>
using namespace std;
int T;
int n;
map<long long, int> m_a;
map<long long, int> m_b;
long long sum_a[1001];
long long sum_b[1001];
long long ans;
int main() {
	ios::sync_with_stdio(false); cout.tie(0); cin.tie(0);

	cin >> T >> n;
	for (int i = 1; i <= n; i++) {
		long long x; cin >> x;
		sum_a[i] = sum_a[i - 1] + x;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			long long temp = sum_a[j] - sum_a[i - 1];//i->j까지 합
			if (m_a.count(temp) == 0) {
				m_a.insert({ temp, 1 });
			}
			else {
				m_a[temp]++;
			}
		}
	}
	cin >> n;
	for (int i = 1; i <= n; i++) {
		long long x; cin >> x;
		sum_b[i] = sum_b[i - 1] + x;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			long long temp = sum_b[j] - sum_b[i - 1];//i->j까지 합
			if (m_b.count(temp) == 0) {
				m_b.insert({ temp, 1 });
			}
			else {
				m_b[temp]++;
			}
		}
	}
	for (auto iter = m_a.begin(); iter != m_a.end(); iter++) {
		long long temp = iter->first;
		long long cnt = iter->second;
		if (m_b.count(T - temp) != 0) {
			ans += cnt * m_b[T - temp];
		}
	}
	cout << ans << "\n";
}