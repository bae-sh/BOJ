#include<iostream>
#include<cmath>
#include<vector>
#include<string>
using namespace std;
string  l;
int L, R,ans;

int go(int x, int digit) {
	int temp = 0;
	string s = to_string(x);
	for (int i = 0; i < digit; i++) {
		temp += (s[i] - '0') * (int)pow(10, l.length() - i - 1);
	}
	temp += 9 * (int)pow(10, l.length() - digit - 1);
	return temp;
}

int main() {
	cin >> l >> R;
	int temp = stoi(l);
	for (int i = 0; i <l.length(); i++) {
		if (l[i] == '8') {
			int m = go(temp, i);
			if (R >= m) {
				temp = m;
				break;
			}
		}
	}
	string result = to_string(temp);
	for (int i = 0; i < result.length(); i++) {
		if (result[i] == '8') ans++;
	}
	cout << ans;
}
