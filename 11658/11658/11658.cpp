#include <cstdio>
int n, m;
int a[1025][1025];
int tree[1025][1025];
void update(int x, int y, int val) {
    for (int i = x; i <= n; i += i & -i) {
        for (int j = y; j <= n; j += j & -j) {
            tree[i][j] += val;
        }
    }
}
int sum(int x, int y) {
    int ans = 0;
    for (int i = x; i > 0; i -= i & -i) {
        for (int j = y; j > 0; j -= j & -j) {
            ans += tree[i][j];
        }
    }
    return ans;
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
            update(i, j, a[i][j]);
        }
    }
    while (m--) {
        int what;
        scanf("%d", &what);
        if (what == 0) {
            int x, y, val;
            scanf("%d %d %d", &x, &y, &val);
            update(x, y, val - a[x][y]);
            a[x][y] = val;
        }
        else {
            int x1, y1, x2, y2;
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            printf("%d\n", sum(x2, y2) - sum(x1 - 1, y2) - sum(x2, y1 - 1) + sum(x1 - 1, y1 - 1));
        }
    }
    return 0;
}