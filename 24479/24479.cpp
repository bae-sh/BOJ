#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M, R;
vector<int> v[100001];
int visited[100001];
int cnt;
void dfs(int cur)
{
	visited[cur] = ++cnt;
	for (int i = 0; i < v[cur].size(); i++)
	{
		int next = v[cur][i];
		if (!visited[next])
		{
			dfs(next);
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> R;
	for (int i = 0; i < M; i++)
	{
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for (int i = 1; i <= N; i++)
	{
		sort(v[i].begin(), v[i].end());
	}
	dfs(R);
	for (int i = 1; i <= N; i++)
	{
		cout << visited[i] << "\n";
	}
}