#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int N;
int cnt = 100001;
string s, res;

void go(bool on)
{
  string temp = s;
  int curCount = 0;

  if (on)
  {
    temp[0] = temp[0] == '1' ? '0' : '1';
    temp[1] = temp[1] == '1' ? '0' : '1';
    curCount += 1;
  }
  for (int i = 1; i < N; i++)
  {
    if (temp[i - 1] != res[i - 1])
    {
      temp[i] = temp[i] == '1' ? '0' : '1';
      if (i - 1 >= 0)
      {
        temp[i - 1] = temp[i - 1] == '1' ? '0' : '1';
      }
      if (i + 1 < N)
      {
        temp[i + 1] = temp[i + 1] == '1' ? '0' : '1';
      }
      curCount += 1;
    }
  }
  if (temp == res)
  {
    cnt = min(cnt, curCount);
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
  cin >> N >> s >> res;
  go(true);
  go(false);
  if (cnt == 100001)
    cnt = -1;
  cout << cnt << '\n';
}