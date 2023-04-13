#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int T;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> T;
  while (T-- > 0)
  {
    int n, d, c;
    int answer = 0;
    vector<pair<int, int>> v[10001];
    int cost[10001];
    for (int i = 1; i <= 10000; i++)
    {
      cost[i] = 987654321;
    }

    cin >> n >> d >> c;
    cost[c] = 0;
    for (int i = 0; i < d; i++)
    {
      int a, b, c;
      cin >> a >> b >> c;
      v[b].push_back({a, c});
    }
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < v[c].size(); i++)
    {
      int nextTime = v[c][i].second;
      int nextCom = v[c][i].first;
      pq.push({-nextTime, nextCom});
      cost[nextCom] = nextTime;
    }

    while (!pq.empty())
    {
      int time = -pq.top().first;
      int com = pq.top().second;
      pq.pop();
      for (int i = 0; i < v[com].size(); i++)
      {
        int nextTime = time + v[com][i].second;
        int nextCom = v[com][i].first;
        if (cost[nextCom] > nextTime)
        {
          pq.push({-nextTime, nextCom});
          cost[nextCom] = nextTime;
        }
      }
    }
    int time = 0;
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
      if (cost[i] != 987654321)
      {
        count += 1;
        time = max(time, cost[i]);
      }
    }
    cout << count << ' ' << time << '\n';
  }
}