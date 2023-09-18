#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

priority_queue<int> pq;
vector<pair<int, int>> v;
int n;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> n;

  for (int i = 0; i < n; i++)
  {
    int d, p;
    cin >> p >> d;
    v.push_back({d, p});
  }
  sort(v.begin(), v.end());

  for (int i = 0; i < v.size(); i++)
  {
    int d = v[i].first;
    int p = v[i].second;

    if (pq.size() < d)
    {
      pq.push(-p);
    }
    else
    {
      if (-pq.top() < p)
      {
        pq.pop();
        pq.push(-p);
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