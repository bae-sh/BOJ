#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  string s = "";
  priority_queue<int> pq;

  for (int i = 0; i < n; i++)
  {
    int m;
    cin >> m;
    if (m == 0)
    {
      if (pq.empty())
      {
        cout << 0 << '\n';
      }
      else
      {
        cout << pq.top() << '\n';
        pq.pop();
      }
    }
    else
    {
      pq.push(m);
    }
  }
}