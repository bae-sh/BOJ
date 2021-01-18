#include<iostream>
#include<map>
using namespace std;

int N, K;
map<long long, long long> cnt;
long long sum[200001];
long long ans;
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		long long x; cin >> x;
		sum[i] = sum[i - 1] + x;
		if (sum[i] == K) ans++;
		ans += cnt[sum[i] - K];
		cnt[sum[i]]++;
	}
	cout << ans;
}