#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<string> v(10001);
vector<string> s(10001);
int n;
string add(string a, string b) {
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	while (a.size() < b.size()) {
		a += "0";
	}
	while (b.size() < a.size()) {
		b += "0";
	}
	string c = "";
	int size = a.size();
	int carry = 0;
	for (int i = 0; i < size; i++) {
		int sum = ((a[i] - '0') + (b[i] - '0') + carry);
		int temp = sum % 10;
		c += (char)(temp + '0');
		carry = sum / 10;
	}
	if (carry != 0) {
		c += (char)(carry + '0');
	}
	reverse(c.begin(), c.end());
	return c;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	v[0] = "1"; v[1] = "2";  v[2] = "3";
	for (int i = 3; i <= 10000; i++) {
		v[i] = add(v[i - 2], v[i - 1]);
		s[i] = add(v[i - 3], v[i - 1]);
	}
	while (cin >> n) {
		cout << s[n] << "\n";
	}
}