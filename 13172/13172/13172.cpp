#include<iostream>
#include<algorithm>
#define MOD 1000000007
using namespace std;
long long ans;
int M;

long long go(long long x, long long k) {
    if (k == 1) return x;
    if (k & 1) return x * go(x, k - 1) % MOD;
    long long res = go(x, k / 2);
    return res * res % MOD;
}

long long gcd(long long a, long long b) {
    long long tmp, n;
    if (a < b) {
        swap(a, b);
    }
    while (b != 0) {
        n = a % b;
        a = b;
        b = n;
    }
    return a;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> M;
    for (int i = 0; i < M; i++) {
        long long a, b; cin>> a >> b;;
        long long g = gcd(a, b);
        a /= g;
        b /= g;
        long long l = go(a, MOD - 2);
        ans += b * l % MOD;
        ans %= MOD;
    }
    
    cout << ans << "\n";
}
