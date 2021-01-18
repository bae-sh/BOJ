#include<iostream>
#define mod 1000000007
using namespace std;
int N, K;
long long num[100001][11];
long long total[11];
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> K;
	for (int i = 1; i <= K; i++) {
		num[i][1] = 1;
		total[1]++;
	}
	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			long long temp = total[i - 1];
			for (int a = j + j; a <= K; a += j) {
				temp -= num[a][i - 1];
			}
			num[j][i] = temp;
			total[i] = (total[i] + temp) % mod;
		}
	}
	cout << total[N] << "\n";
}