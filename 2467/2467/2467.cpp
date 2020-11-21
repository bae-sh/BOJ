#include<iostream>
#include<algorithm>
using namespace std;

long long w[100001];
int N;
long long ans = 5000000000; int first, second;
int lower_bound(long long arr[], long long target, int size)
{
	int mid, start, end;
	start = 0, end = size - 1;

	while (end > start) 
	{
		mid = (start + end) / 2;
		if (arr[mid] >= target) 
			end = mid;
		else start = mid + 1; 
	}
	return end;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> w[0];
	for (int i = 1; i < N; i++) {
		cin >> w[i];
		if (abs(ans) > abs(w[i - 1] + w[i])) {
			ans = w[i - 1] + w[i]; first = i - 1; second = i;
		}
	}
	for (int i = 0; i < N; i++) {
		int find = abs(w[i]);
		int index = lower_bound(w, find, N);
		if (w[i] > 0 || w[index] < 0) {
			break;
		}
		if (abs(ans) > abs(w[i] + w[index])) {
			ans = w[i] + w[index];
			first = i; second = index;
		}
		index--;
		if (index >= 0 && i != index) {
			if (abs(ans) > abs(w[i] + w[index])) {
				ans = w[i] + w[index];
				first = i; second = index;
			}
		}
	}
	cout << w[first] << " " << w[second];
}