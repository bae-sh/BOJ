#include<iostream>
using namespace std;
int N, M, ans;
int go(int n, int m) {
	if (m == 0 || n == 0) {
		return ans;
	}
	if (n > m) {
		n %= m;
	}
	if (n == 0) {
		return ans;
	}
	if (n % m == 0) {
		return ans;
	}
	int x = m / n;
	if (m%n == 0) {
		x--;
	}
	ans += x * n;
	go(n, m - x * n);
}

int main() {
	cin >> N >> M;
	cout << go(N, M);
}