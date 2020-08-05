#include<iostream>
#include<string>
#include<queue>
using namespace std;
int N;
int x;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	queue<int> q;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string str1;
		cin >> str1;
		if (str1=="push") {
			cin >> x;
			q.push(x);
		}
		else if (str1 == "pop") {
			if (q.empty()) {
				cout << "-1" << "\n";
			}
			else {
				cout << q.front() << "\n";
				q.pop();
			}
		}
		else if (str1 == "size") {
			cout << q.size() << "\n";
		}
		else if (str1 == "empty") {
			if (q.empty()) {
				cout << "1" << "\n";
			}
			else {
				cout << "0" << "\n";
			}
		}
		else if (str1 == "front") {
			if (q.empty()) {
				cout << "-1" << "\n";
			}
			else {
				cout << q.front() << "\n";
			}
		}
		else if (str1 == "back") {
			if (q.empty()) {
				cout << "-1" << "\n";
			}
			else {
				cout << q.back() << "\n";
			}
		}
	}
}