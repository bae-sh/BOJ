#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int N;
priority_queue<int> pq;

vector<pair<int, int>> v;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++)
  {
    int a, b;
    cin >> a >> b;
    v.push_back({a, b});
  }

  sort(v.begin(), v.end());

  for (int i = 0; i < v.size(); i++)
  {
    int a = v[i].first;
    int score = v[i].second;

    if (pq.size() < a)
    {
      pq.push(-score);
    }
    else
    {
      if (-pq.top() < score)
      {
        pq.pop();
        pq.push(-score);
      }
    }
  }

  int ans = 0;

  while (!pq.empty())
  {
    ans += -pq.top();
    pq.pop();
  }

  cout << ans << '\n';
}