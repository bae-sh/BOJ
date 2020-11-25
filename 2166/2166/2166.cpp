#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int N;
vector<pair<long long, long long>> p;
long long ans;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b; cin >> a >> b;
		p.push_back({ a,b });
	}
	pair<long long, long long> p1 = p[0];
	for (int i = 1; i < N - 1; i++) {
		pair<long long, long long> p2 = p[i];
		pair<long long, long long> p3 = p[i + 1];
		ans += ((p2.first - p1.first) * (p3.second - p1.second) - (p2.second - p1.second) * (p3.first - p1.first));
	}
	printf("%.1lf", abs(ans / 2.0));
}