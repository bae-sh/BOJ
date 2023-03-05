#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#define MAX 1001
using namespace std;
int T;
char map[MAX][MAX];
int fire[MAX][MAX];
int visited[MAX][MAX];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N, M, sx, sy;

vector<pair<int, int>> f;
int go()
{
  queue<pair<int, int>> list;
  list.push({sx, sy});
  int ans = 0;
  while (!list.empty())
  {
    int x = list.front().first;
    int y = list.front().second;
    list.pop();

    for (int i = 0; i < 4; i++)
    {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (0 <= nx && nx < N && 0 <= ny && ny < M)
      {
        if (map[nx][ny] == '#')
          continue;
        if (visited[nx][ny] != -1)
        {
          continue;
        }
        if (fire[nx][ny] > visited[x][y] + 1 || fire[nx][ny] == -1)
        {
          visited[nx][ny] = visited[x][y] + 1;
          list.push({nx, ny});
        }
      }
      else
      {
        return visited[x][y] + 1;
      }
    }
  }
  return -1;
}
void moveFire()
{
  queue<pair<int, int>> list;
  for (int i = 0; i < f.size(); i++)
  {
    list.push({f[i].first, f[i].second});
  }

  while (!list.empty())
  {
    int x = list.front().first;
    int y = list.front().second;
    list.pop();

    for (int i = 0; i < 4; i++)
    {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (0 <= nx && nx < N && 0 <= ny && ny < M)
      {
        if (fire[nx][ny] == -1 && map[nx][ny] != '#')
        {
          fire[nx][ny] = fire[x][y] + 1;
          list.push({nx, ny});
        }
      }
    }
  }
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> T;

  while (T--)
  {
    cin >> M >> N;
    memset(fire, -1, sizeof(fire));
    memset(visited, -1, sizeof(visited));
    f.clear();

    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < M; j++)
      {
        char c;
        cin >> c;
        map[i][j] = c;

        if (c == '*')
        {
          f.push_back({i, j});
          fire[i][j] = 0;
        }
        else if (c == '@')
        {
          sx = i;
          sy = j;
          visited[i][j] = 0;
        }
      }
    }
    moveFire();
    int ans = go();
    if (ans == -1)
    {
      cout << "IMPOSSIBLE" << '\n';
    }
    else
    {
      cout << ans << '\n';
    }
  }
}