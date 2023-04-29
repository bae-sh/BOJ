#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N;
long long MOD = 987654321;
long long dp[10001];

long long shake(int num)
{
  if (dp[num] != -1)
    return dp[num];

  long long value = 0;

  for (int i = 2; i <= num; i++)
  {
    int left = i - 2;
    int right = num - i;
    if (left % 2 == 0 && right % 2 == 0)
    {
      value = value + ((shake(left) * shake(right)) % MOD);
      value %= MOD;
    }
  }
  dp[num] = value;
  return value;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> N;

  memset(dp, -1, sizeof(dp));
  dp[0] = 1;

  cout << shake(N);
}
