#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;

int hp[10];
int damage[10];
int ans;

void breakEgg(int index)
{
  if (index == N)
  {
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
      if (hp[i] <= 0)
      {
        cnt++;
      }
    }
    ans = max(ans, cnt);
    return;
  }
  if (hp[index] <= 0)
  {
    breakEgg(index + 1);
    return;
  }
  bool flag = false;
  for (int i = 0; i < N; i++)
  {
    if (i == index || hp[i] <= 0)
      continue;
    flag = true;
    hp[index] -= damage[i];
    hp[i] -= damage[index];
    breakEgg(index + 1);

    hp[index] += damage[i];
    hp[i] += damage[index];
  }
  if (!flag)
    breakEgg(index + 1);
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
    hp[i] = x;
    damage[i] = y;
  }

  breakEgg(0);

  cout << ans;
}