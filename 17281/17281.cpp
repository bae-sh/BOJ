#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int N;
int order[9];
bool check[9];
int ans;
vector<int> arr[51];

void playGame()
{

  int score = 0;
  int count = 0;

  for (int i = 0; i < N; i++)
  {

    int player[] = {0, 0, 0};
    int outPlayer = 0;
    while (outPlayer < 3)
    {
      int index = order[count % 9];
      int hitScore = arr[i][index];
      if (hitScore == 0)
      {
        outPlayer += 1;
      }
      else if (hitScore == 1)
      {
        if (player[2] == 1)
          score += 1;
        player[2] = player[1];
        player[1] = player[0];
        player[0] = 1;
      }
      else if (hitScore == 2)
      {
        for (int i = 0; i < 2; i++)
        {
          if (player[2 - i] == 1)
            score += 1;
        }
        player[2] = player[0];
        player[0] = 0;
        player[1] = 1;
      }
      else if (hitScore == 3)
      {
        for (int i = 0; i < 3; i++)
        {
          if (player[i] == 1)
            score += 1;
        }
        player[0] = 0;
        player[1] = 0;
        player[2] = 1;
      }
      else
      {
        score += 1;
        for (int i = 0; i < 3; i++)
        {
          if (player[i] == 1)
            score += 1;
          player[i] = 0;
        }
      }
      count += 1;
    }
  }
  ans = max(ans, score);
}
void makeOrder(int index)
{
  if (index == 9)
  {
    playGame();
    return;
  }
  if (index == 3)
    index += 1;
  for (int i = 1; i < 9; i++)
  {
    if (!check[i])
    {
      order[index] = i;
      check[i] = true;
      makeOrder(index + 1);
      check[i] = false;
      order[index] = 0;
    }
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
    for (int j = 0; j < 9; j++)
    {
      int x;
      cin >> x;
      arr[i].push_back(x);
    }
  }
  makeOrder(0);
  cout << ans;
}
