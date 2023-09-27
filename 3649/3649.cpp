#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void twoPointer(vector<int> v, int len)
{
  int l = 0, r = v.size() - 1;
  while (l < r)
  {
    int sum = v[l] + v[r];
    if (sum == len)
    {
      cout << "yes " << v[l] << ' ' << v[r] << '\n';
      return;
    }
    if (sum < len)
    {
      l += 1;
    }
    else if (sum > len)
    {
      r -= 1;
    }
  }
  cout << "danger\n";
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int NANO = 10000000;
  int len;

  while (cin >> len)
  {
    int size;
    cin >> size;

    vector<int> v;
    for (int i = 0; i < size; i++)
    {
      int x;
      cin >> x;
      v.push_back(x);
    }
    sort(v.begin(), v.end());
    twoPointer(v, len * NANO);
  }
}