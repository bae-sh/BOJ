#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, K;
bool dp[300001];
vector<int> v;
vector<pair<int, int>> p;
int ans;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> K;

  for (int i = 0; i < N; i++)
  {
    int x;
    cin >> x;
    v.push_back(x);
  }

  if (K == 1)
  {
    cout << v[N - 1] - v[0];
  }
  else
  {
    for (int i = 0; i < N - 1; i++)
    {
      p.push_back({v[i + 1] - v[i], i});
    }

    sort(p.begin(), p.end());
    reverse(p.begin(), p.end());

    for (int i = 0; i < K - 1; i++)
    {
      dp[p[i].second] = true;
    }

    int start = v[0];
    for (int i = 0; i < N - 1; i++)
    {
      if (dp[i])
      {
        ans += v[i] - start;
        start = v[i + 1];
      }
    }
    ans += v[N - 1] - start;
    cout << ans;
  }
}