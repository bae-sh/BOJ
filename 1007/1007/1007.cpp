#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<cmath>
#define INF 9223372036854775807
using namespace std;
int T;
long long ans;

int main() {
	scanf("%d", &T);

	while (T--) {
		int n; scanf("%d", &n);
		ans = INF;
		vector<pair<int, int>> v;
		vector<int> order;
		for (int i = 0; i < n / 2; i++)
			order.push_back(0);
		for (int i = 0; i < n / 2; i++)
			order.push_back(1);

		for (int i = 0; i < n; i++) {
			int a, b; cin >> a >> b;
			v.push_back({ a,b });
		}
		do {
			long long x = 0, y = 0;
			for (int i = 0; i < n; i++) {
				if (order[i] == 0) {
					x += v[i].first;
					y += v[i].second;
				}
				else {
					x -= v[i].first;
					y -= v[i].second;
				}
			}
			long long sum = pow(x, 2) + pow(y, 2);
			ans = min(ans, sum);
		} while (next_permutation(order.begin(), order.end()));
		printf("%.12lf\n", sqrt(ans));
	}
}