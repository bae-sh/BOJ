#include<iostream>
#include<map>
#include<string>
using namespace std;

map<string, string> m;
int N, M;
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s1, s2; cin >> s1 >> s2;
		m.insert({ s1,s2 });
	}
	for (int i = 0; i < M; i++) {
		string s; cin >> s;
		cout << m[s] << "\n";
	}
}