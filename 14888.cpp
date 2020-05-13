#include <iostream>
#include<algorithm>
static int Max = -1000000000;
static int Min = 1000000000;
static int n;
void opp(int front, int oper[], int a[], int cnt) {
	if (oper[0] > 0) {
		int _front = front + a[cnt];
		oper[0]--;
		opp(_front, oper, a, cnt + 1);
		oper[0]++;
	}
	if (oper[1] > 0) {
		int _front = front - a[cnt];
		oper[1]--;
		opp(_front, oper, a, cnt + 1);
		oper[1]++;
	}
	if (oper[2] > 0) {
		int _front = front * a[cnt];
		oper[2]--;
		opp(_front, oper, a, cnt + 1);
		oper[2]++;
	}
	if (oper[3] > 0) {
		int _front = front / a[cnt];
		oper[3]--;
		opp(_front, oper, a, cnt + 1);
		oper[3]++;
	}
	if (cnt == n) {
		Max = std::max(front, Max);
		Min = std::min(front, Min);
	}
}
int main() {
	std::cin >> n;
	int *a = new int[n];
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	int oper[4];
	for (int i = 0; i < 4; i++) {
		std::cin >> oper[i];
	}
	opp(a[0], oper, a, 1);
	std::cout << Max << std::endl;
	std::cout << Min << std::endl;
}