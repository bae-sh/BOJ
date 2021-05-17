#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int N;
string num[81][81];//
bool check(int cur_idx, char cur_num) {
	for (int i = 1; i <= cur_idx; i++) {
		num[cur_idx][i] = num[cur_idx - 1][i - 1] + cur_num;
	}
	for (int i = 1; i <= cur_idx / 2; i++) {
		if (num[cur_idx - i][i] == num[cur_idx][i]) return false;
	}
	return true;
}
bool makeNum(int cur_idx) {
	if (cur_idx > N) return true;
	for (int i = 1; i <= 3; i++) {
		char c = i + '0';
		if (check(cur_idx, c)) {
			if (makeNum(cur_idx + 1)) return true;
		}
	}
	return false;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N;
	makeNum(1);
	for (int i = 1; i <= N; i++) {
		cout << num[i][1];
	}
}