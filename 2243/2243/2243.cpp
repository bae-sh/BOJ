#include<iostream>
#define MAX 1000000
using namespace std;
int n;
int tree[MAX * 3];
void update(int index, int target, int diff, int start, int end) {
	if (target<start || target>end) {
		return;
	}
	tree[index] += diff;
	if (start == end) {
		return;
	}
	int mid = (start + end) / 2;
	update(index * 2, target, diff, start, mid);
	update(index * 2 + 1, target, diff, mid + 1, end);
}
int pull(int index, int target, int start, int end) {
	tree[index]--;
	if (start == end) {
		return start;
	}
	int mid = (start + end) / 2;
	if (tree[index * 2] >= target) {
		return pull(index * 2, target, start, mid);
	}
	else {
		return pull(index * 2 + 1, target - tree[index * 2], mid + 1, end);
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;
	while (n--) {
		int a, b, c;
		cin >> a;
		if (a == 1) {
			cin >> b;
			cout << pull(1, b, 1, MAX) << "\n";
		}
		else {
			cin >> b >> c;
			update(1, b, c, 1, MAX);
		}
	}
}