#include <iostream>
#include <algorithm>
#include <string.h>
#include <stack>
using namespace std;
int dp[1001][1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s1, s2;
    cin >> s1 >> s2;
    for (int i = 0; i < s1.length(); i++)
    {
        char a = s1[i];
        for (int j = 0; j < s2.length(); j++)
        {
            char b = s2[j];
            if (a == b)
            {
                dp[i + 1][j + 1] = dp[i][j] + 1;
            }
            else
            {
                dp[i + 1][j + 1] = dp[i][j + 1] > dp[i + 1][j] ? dp[i][j + 1] : dp[i + 1][j];
            }
        }
    }
    int len1 = s1.length();
    int len2 = s2.length();
    stack<char> st;
    cout << dp[len1][len2] << "\n";
    while (dp[len1][len2])
    {
        if (dp[len1][len2] == dp[len1 - 1][len2])
        {
            len1--;
        }
        else if (dp[len1][len2] == dp[len1][len2 - 1])
        {
            len2--;
        }
        else if (dp[len1][len2] - 1 == dp[len1 - 1][len2 - 1])
        {
            st.push(s1[len1 - 1]);
            len1--;
            len2--;
        }
    }

    while (!st.empty())
    {
        cout << st.top();
        st.pop();
    }
}