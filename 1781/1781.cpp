#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

priority_queue<int> pq;
int N;
long long ans;
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

  int day = 1;
  int idx = 0;
  while (idx < v.size())
  {
    int a = v[idx].first;
    int b = v[idx].second;
    if (a >= day)
    {
      pq.push(-b);
      day += 1;
    }
    else
    {
      // 날짜가 지난 경우
      if (-pq.top() < b)
      {
        pq.pop();
        pq.push(-b);
      }
    }
    idx += 1;
  }

  while (!pq.empty())
  {
    ans += -pq.top();
    pq.pop();
  }
  cout << ans << '\n';
}