#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int N, M;
int answer = 2100000000;
vector<int> arr;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> N >> M;
  for (int i = 0; i < N; i++)
  {
    int n;
    cin >> n;
    arr.push_back(n);
  }
  sort(arr.begin(), arr.end());

  int l = 0, r = 0;
  while (r < N)
  {
    int gap = arr[r] - arr[l];

    if (gap >= M)
    {
      answer = min(answer, gap);
      if (l == r)
        r += 1;
      else
        l += 1;
    }
    else
    {
      r += 1;
    }
  }
  cout << answer;
}