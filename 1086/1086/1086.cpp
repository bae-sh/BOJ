#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int n;
int k;
vector<string> v;
long long dp[(1 << 15)][101];
int ten[51];
int mod[16];
long long gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    }
    else {
        return gcd(b, a % b);
    }
}
int go_mod(string s) {
    int len = s.length();
    int ans = 0;
    for (int i = 0; i < len; i++) {
        ans += (((s[len - i - 1] - '0') % k) * (ten[i] % k));
        ans %= k;
    }
    return ans;
}
long long dfs(int num ,int left) {
    long long& ans = dp[num][left];
    if (ans != -1) {
        return ans;
    }
    if (num == ((1 << n) - 1)) {
        if (left == 0) {
            return 1;
        }
        else {
            return 0;
        }
    }
    ans = 0;
    for (int i = 0; i < n; i++) {
        if (!(num & (1 << i))) {
            ans += dfs((num | (1 << i)), (((left * ten[v[i].length()]) % k + mod[i]) % k) % k);
        }
    }
    return ans;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;
    for (int i = 0; i < n; i++) {
        string x; cin >> x;
        v.push_back(x);
    }
    cin >> k;

    ten[0] = 1;
    for (int i = 1; i < 51; i++) {
        ten[i] = (ten[i - 1] * (10 % k)) % k;
    }
    for (int i = 0; i < n; i++) {
        mod[i] = go_mod(v[i]);
    }

    memset(dp, -1, sizeof(dp));
    long long ans = dfs(0, 0);
    long long fac = 1;
    for (int i = 1; i <= n; i++) {
        fac *= i;
    }
    long long g = gcd(fac, ans);
    cout << ans / g << "/" << fac / g << "\n";
}