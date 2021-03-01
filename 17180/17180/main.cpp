#include <iostream>

using namespace std;
int dp[1005][1005];
int L1, L2;
string S1, S2;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> L1 >> L2 >> S1 >> S2;
    for (int i = 1; i <= L1; i++) {
        dp[i][1] = dp[i - 1][1] + abs(S1[i - 1] - S2[0]);
    }
    for (int i = 1; i <= L2; i++) {
        dp[1][i] = dp[1][i - 1] + abs(S1[0] - S2[i - 1]);
    }
    for (int i = 2; i <= L1; i++) {
        for (int j = 2; j <= L2; j++) {
            if (S1[i - 1] == S2[j - 1]) dp[i][j] = min({ dp[i - 1][j - 1],dp[i - 1][j],dp[i][j - 1] });
            else dp[i][j] = min({ dp[i - 1][j - 1],dp[i - 1][j],dp[i][j - 1] }) + abs(S1[i - 1] - S2[j - 1]);
        }
    }
    cout<<dp[L1][L2]<<"\n";
}
