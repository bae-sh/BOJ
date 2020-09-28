#include<iostream>
#include<algorithm>
using namespace std;
int L, A, B, C, D, M, K;

int main() {
	cin >> L >> A >> B >> C >> D;
	M = B / D;
	if (B%D) {
		M++;
	}
	K = A / C;
	if (A%C) {
		K++;
	}
	cout << L - max(M, K);
}