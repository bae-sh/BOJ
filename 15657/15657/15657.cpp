#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int N, M;
int num[8];
void go(int depth, string s, int index) {
	if (depth == M) {
		cout << s << "\n";
		return;
	}
	else {
		for (int i = index; i < N; i++) {
			if (depth == 0) {
				go(depth + 1, to_string(num[i]), i);
			}
			else {
				go(depth + 1, s + " " + to_string(num[i]), i);
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	sort(num, num + N);
	go(0, "", 0);
}