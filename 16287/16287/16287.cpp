#include<iostream>
#include<algorithm>
#define MAX 799995
using namespace std;
int w, n;
int num[5000];
bool weight[MAX];
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> w >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i - 1; j++) {
			if (num[i - 1] + num[j] < w) {
				weight[num[i - 1] + num[j]] = true;
			}
		}

		for (int j = i + 1; j < n; j++) {
			if (num[i] + num[j] > w) continue;
			if (weight[w - num[i] - num[j]]) {
				cout << "YES\n";
				return 0;
			}
		}
		
	}
	cout << "NO" << '\n';
}