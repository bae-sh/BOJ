#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, answer;
struct Point
{
  int x;
  int y;
};
vector<Point> v;

bool cmp(const Point &p1, const Point &p2)
{
  if (p1.x < p2.x)
  {
    return true;
  }
  else if (p1.x == p2.x)
  {
    return p1.y < p2.y;
  }
  else
  {
    return false;
  }
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> N;
  for (int i = 0; i < N; i++)
  {
    int x, y;
    cin >> x >> y;
    v.push_back({x, y});
  }
  sort(v.begin(), v.end(), cmp);
  int l = v[0].x, r = v[0].y;

  for (int i = 0; i < N; i++)
  {
    int x = v[i].x, y = v[i].y;
    if (l <= x && x <= r)
    {
      r = max(r, y);
    }
    else
    {
      answer += r - l;
      l = x;
      r = y;
    }
  }
  answer += r - l;
  cout << answer;
}