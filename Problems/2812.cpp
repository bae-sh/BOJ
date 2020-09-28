#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

int main() {
	int n, k;
	char str[500001];
	deque<char> dq;

	scanf("%d %d", &n, &k);
	scanf("%s", str);

	for (int i = 0; i < n; i++) {
		while (k && !dq.empty() && dq.back() < str[i]) {
			dq.pop_back();
			k--;
		}
		dq.push_back(str[i]);
	}
	for (int i = 0; i < dq.size() - k; i++) {
		printf("%c", dq[i]);
	}
}