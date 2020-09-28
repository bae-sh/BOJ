#include<iostream>
using namespace std;
int f;
long long ans, num;
int main() {
	cin >> f >> num;
	switch (f) {
	case 1:
		ans = 8 * num;
		break;
	case 2:
		if (num % 2) {
			ans = 8 * (num / 2) + 7;
		}
		else {
			ans = 8 * (num / 2) + 1;
		}
		break;
	case 3:
		ans = 4 * num + 2;
		break;
	case 4:
		if (num % 2) {
			ans = 8 * (num / 2) + 5;
		}
		else {
			ans = 8 * (num / 2) + 3;
		}
		break;
	case 5:
		ans = 8 * num + 4;
	}
	cout << ans;
}