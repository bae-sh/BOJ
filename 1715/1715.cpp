#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
int N;
int ans;
priority_queue<int> pq;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		pq.push(-x);
	}

	while (pq.size() > 1)
	{
		int x, y, z;
		x = -pq.top();
		pq.pop();
		y = -pq.top();
		pq.pop();

		z = x + y;
		pq.push(-z);
		ans += z;
	}
	cout << ans << "\n";
}