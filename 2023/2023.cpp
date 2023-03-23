#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool prime[10001];
vector<int> primeNumbers;
vector<int> answer[9];
int N;
bool checkPrime(int num)
{
  for (int i = 0; i < primeNumbers.size(); i++)
  {
    int primeNum = primeNumbers[i];
    if (num <= primeNum)
      return true;
    if (num % primeNum == 0)
      return false;
  }
  return true;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> N;

  for (int i = 2; i <= 10000; i++)
    prime[i] = true;
  for (int i = 2; i <= 100; i++)
  {
    if (prime[i])
    {
      for (int j = i + i; j <= 10000; j += i)
      {
        prime[j] = false;
      }
    }
  }
  for (int i = 2; i < 10001; i++)
  {
    if (prime[i])
      primeNumbers.push_back(i);
  }
  for (int i = 2; i < 10; i++)
  {
    if (prime[i])
      answer[1].push_back(i);
  }
  for (int i = 2; i <= N; i++)
  {
    for (int j = 0; j < answer[i - 1].size(); j++)
    {
      int num = answer[i - 1][j];
      for (int j = 1; j < 10; j += 2)
      {
        int nextNumber = num * 10 + j;
        if (checkPrime(nextNumber))
          answer[i].push_back(nextNumber);
      }
    }
  }
  for (int i = 0; i < answer[N].size(); i++)
  {
    cout << answer[N][i] << '\n';
  }
}