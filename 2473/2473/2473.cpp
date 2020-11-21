#include<iostream>
#include<algorithm>
using namespace std;
long long solution[5000];
int N;
int l, r, m;
long long ans=5000000000;
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie();

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> solution[i];
	}
	sort(solution, solution + N);
	for (int i = 0; i < N; i++) {
		int left = 0; int right = N - 1;
		while (left < right) {
			if (left == i) left++;
			else if (right == i) right--;
			else {
				long long temp = solution[left] + solution[right] + solution[i];
				if (abs(temp) < ans) {
					ans = abs(temp);
					l = left, r = right; m = i;
				}
				if (temp > 0) {
					right--;
				}
				else {
					left++;
				}
			}

		}
	}
	long long a[3] = { solution[l],solution[r],solution[m] };
	sort(a, a + 3);
	cout << a[0] << " " << a[1] << " " << a[2];
}