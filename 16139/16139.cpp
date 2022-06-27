#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;

string s;
int q;
int dp[200001][26];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> s;
	cin >> q;
	for (int i = 1; i <= s.length(); i++)
	{
		for (int j = 0; j < 26; j++)
		{
			dp[i][j] = dp[i - 1][j];
		}
		int idx = s[i - 1] - 'a';
		dp[i][idx] += 1;
	}
	for (int i = 0; i < q; i++)
	{
		char c;
		int x, y;
		cin >> c >> x >> y;
		int idx = c - 'a';
		cout << dp[y + 1][idx] - dp[x][idx] << "\n";
	}
}