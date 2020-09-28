#include<iostream>
#include<algorithm>
using namespace std;
int T;
int x,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T-- > 0) {
		cin >> x;
		int two = 0;
		int five = 0;
		for (int i = 2; i <= x; i*=2) {
			two += x / i;
		}
		for (int i = 5; i <= x; i *= 5) {
			five += x / i;
		}
		ans = two > five ? five : two;
		cout << ans << "\n";
	}
}