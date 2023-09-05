#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <queue>
#define INF 987654321
using namespace std;

int V, E;
int Dist[401][401];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> V >> E;
	for (int i = 1; i <= V; i++)
	{
		for (int j = 1; j <= V; j++)
		{
			Dist[i][j] = INF;
		}
	}
	for (int i = 0; i < E; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		Dist[a][b] = c;
	}

	for (int k = 1; k <= V; k++)
	{
		for (int i = 1; i <= V; i++)
		{
			for (int j = 1; j <= V; j++)
			{
				if (Dist[i][j] > Dist[i][k] + Dist[k][j])
					Dist[i][j] = Dist[i][k] + Dist[k][j];
			}
		}
	}

	int ans = INF;
	for (int i = 1; i <= V; i++)
	{
		ans = min(ans, Dist[i][i]);
	}
	cout << ((ans == INF) ? -1 : ans);
}