#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

int N, M;
bool used[10001];
vector<int> v;

void print(int count, string s)
{
  if (count == M)
  {
    cout << s << '\n';
    return;
  }

  for (int i = 0; i < v.size(); i++)
  {
    print(count + 1, s + to_string(v[i]) + " ");
  }
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M;
  for (int i = 0; i < N; i++)
  {
    int x;
    cin >> x;
    if (!used[x])
    {
      v.push_back(x);
      used[x] = true;
    }
  }
  sort(v.begin(), v.end());
  print(0, "");
}