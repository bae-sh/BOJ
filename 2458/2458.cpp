#include <iostream>
#include <algorithm>

using namespace std;
int N, M;
int cost[501][501];
int sum = 0;
int MAX = 987654321;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M;
  for (int i = 1; i <= N; i++)
  {
    for (int j = 1; j <= N; j++)
    {
      cost[i][j] = MAX;
    }
  }
  for (int i = 0; i < M; i++)
  {
    int a, b;
    cin >> a >> b;
    cost[a][b] = 1;
  }
  for (int k = 1; k <= N; k++)
  {
    for (int i = 1; i <= N; i++)
    {
      for (int j = 1; j <= N; j++)
      {

        if (cost[i][k] + cost[k][j] < cost[i][j])
        {
          cost[i][j] = cost[i][k] + cost[k][j];
        }
      }
    }
  }
  for (int i = 1; i <= N; i++)
  {
    int cnt = 1;
    for (int j = 1; j <= N; j++)
    {
      if (cost[i][j] != MAX || cost[j][i] != MAX)
      {
        cnt += 1;
      }
    }
    if (cnt == N)
      sum += 1;
  }

  cout << sum;
}