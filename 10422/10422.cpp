#include <iostream>

using namespace std;

long long D[5001];
void init()
{
  D[0] = 1;

  for (int i = 2; i <= 5000; i += 2)
  {
    for (int j = 2; j <= i; j += 2)
    {
      D[i] += D[j - 2] * D[i - j];
      D[i] %= 1000000007;
    }
  }
}

int main(void)
{
  int tc;
  cin >> tc;

  init();

  for (int t = 0; t < tc; t++)
  {
    int n;
    cin >> n;
    cout << D[n] << endl;
  }
}