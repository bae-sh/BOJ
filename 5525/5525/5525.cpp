#include<iostream>
#include<string>
using namespace std;

int N, M;
string s;
int cnt[1000001];
int ans;
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> M >> s;
	for (int i = 0; i < M - 2; i++) {
		if (s[i] == 'I' && s[i + 1] == 'O' && s[i + 2] == 'I') {
			cnt[i + 2] = cnt[i] + 1;
		}
	}
	for (int i = 0; i < M; i++) {
		if (cnt[i] >= N) {
			ans++;
		}
	}
	cout << ans << "\n";
}