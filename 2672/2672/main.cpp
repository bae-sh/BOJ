#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, ans;
int _y[10001];
int cur_x;
struct p {
    int x, y1, y2;
    int position;//left 1 right 2
    bool operator < (p other) {
        if (x == other.x) return position < other.position;
        else return x < other.x;
    }
};
int cal() {
    int cnt = 0;
    for (int i = 1; i < 10001; i++) {
        if (_y[i] > 0) {
            cnt++;
        }
    }
    return cnt;
}

vector<p> v;
int main(int argc, const char* argv[]) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        double a, b, c, d; cin >> a >> b >> c >> d;
        p temp;
        temp.x = a * 10;
        temp.y1 = b * 10;
        temp.y2 = b * 10 + d * 10;
        temp.position = 1;
        v.push_back(temp);
        temp.x = a * 10 + c * 10;
        temp.position = 2;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    cur_x = v[0].x;
    for (int i = 0; i < v.size(); i++) {
        auto cur = v[i];
        ans += cal() * (v[i].x - cur_x);
        cur_x = cur.x;
        if (cur.position == 1) {
            for (int index = cur.y1 + 1; index <= cur.y2; index++) {
                _y[index]++;
            }
        }
        else {
            for (int index = cur.y1 + 1; index <= cur.y2; index++) {
                _y[index]--;
            }
        }
    }
    if (ans % 100 == 0) {
        cout << ans / 100 << "\n";
    }
    else {
        cout << fixed;
        cout.precision(2);
        cout << ans / 100.0 << "\n";
    }
    return 0;
}
