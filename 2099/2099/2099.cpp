#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N, K, M;
vector<int> v[201];
bool possible[201][1000300];

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> K >> M;
	for (int i = 1; i <= N; i++) {
		int a, b; cin >> a >> b;
		v[i].push_back(a);
		v[i].push_back(b);
	}

}