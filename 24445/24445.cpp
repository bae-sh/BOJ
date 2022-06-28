#include <iostream>
#include <queue>
#include <deque>
#include <string.h>
#include <math.h>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> graph[100001];
int visited[100001];
int cnt = 1;

void bfs(int r)
{
	queue<int> q;
	q.push(r);
	visited[r] = cnt++;
	while (!q.empty())
	{
		int inq = q.front();

		q.pop();

		for (int i = 0; i < graph[inq].size(); i++)
		{
			int temp = graph[inq][i];
			if (!visited[temp])
			{
				q.push(temp);
				visited[temp] = cnt++;
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m, r;
	cin >> n >> m >> r;
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (int i = 1; i <= n; i++)
	{
		sort(graph[i].begin(), graph[i].end(), greater<>());
	}
	bfs(r);
	for (int i = 1; i <= n; i++)
	{
		cout << visited[i] << "\n";
	}
}