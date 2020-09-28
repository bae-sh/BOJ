#include<iostream>
#include<string>
#include<math.h>
using namespace std;
int A[26];
int B[26];
int ans;
int main() {
	string x, y;
	cin >> x >> y;
	for (int i = 0; i < x.length(); i++) {
		A[x[i] - 'a']++;
	}
	for (int i = 0; i < y.length(); i++) {
		B[y[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++) {
		if (A[i] != B[i]) {
			ans += abs(A[i] - B[i]);
		}
	}
	cout << ans;
}