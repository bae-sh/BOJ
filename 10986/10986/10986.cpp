#include<iostream>
#include<map>
using namespace std;
int N, M;
long long sum[1000001];
long long ans;
map<long long, long long> m;
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		long long x; cin >> x;
		sum[i] = sum[i - 1] + x;
		long long num = sum[i] % M;
		if (num == 0) {
			ans++;
		}
		ans += m[num];
		m[num]++;
	}
	cout << ans << "\n";
}