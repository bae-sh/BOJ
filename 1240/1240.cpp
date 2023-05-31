#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int N, M;

vector<pair<pair<int, int>, int>> v;
int dist[1001][1001];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M;
  for (int i = 0; i <= N; i++)
  {
    for (int j = 0; j <= N; j++)
      dist[i][j] = 987654321;
    dist[i][i] = 0;
  }

  for (int i = 0; i < N - 1; i++)
  {
    int x, y, z;
    cin >> x >> y >> z;

    dist[x][y] = z;
    dist[y][x] = z;
  }

  for (int k = 1; k <= N; k++)
  {
    for (int i = 1; i <= N; i++)
    {
      for (int j = 1; j <= N; j++)
      {
        if (dist[i][j] > dist[i][k] + dist[k][j])
        {
          dist[i][j] = dist[i][k] + dist[k][j];
        }
      }
    }
  }
  for (int i = 0; i < M; i++)
  {
    int x, y;
    cin >> x >> y;
    cout << dist[x][y] << '\n';
  }
}