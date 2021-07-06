#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct line {
    int s, e, num;
    bool operator < (line& a) {
        if (s == a.s) return e > a.e;
        return s < a.s;
    }
};


int N, M;
int MIN = -1, MAX = -1;
int Right;
vector<line> l1;// 0 을 지나지 않는것과 지나는것
vector<line> l2;
bool ans[500001];

int main(int argc, const char* argv[]) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    long long minA = 1e12, maxB = -1;

    for (int i = 1; i <= M; i++) {
        long long a, b; cin >> a >> b;
        line l;
        l.s = a; l.e = b; l.num = i;
        if (a <= b) {
            l1.push_back(l);
        }
        else {
            minA = min(minA, a);
            maxB = max(maxB, b);
            l.e += N;
            l2.push_back(l);
        }
        ans[i] = true;
    }
    sort(l1.begin(), l1.end());
    sort(l2.begin(), l2.end());
    for (int i = 0; i < l1.size(); i++) {
        line l = l1[i];
        if (l.e <= Right) {
            ans[l.num] = false;
        }
        else {
            Right = l.e;
        }
        if (minA <= l.s) ans[l.num] = false;
        if (l.e <= maxB) ans[l.num] = false;
    }
    Right = 0;
    for (int i = 0; i < l2.size(); i++) {
        line l = l2[i];
        if (l.e <= Right) {
            ans[l.num] = false;
        }
        else {
            Right = l.e;
        }
    }
    for (int i = 1; i <= M; i++) {
        if (ans[i]) {
            cout << i <<  " ";
        }
    }
    return 0;
}