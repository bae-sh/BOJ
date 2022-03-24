#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int t, d, n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while(t--){
        cin >> d >> n;
        int killed[1025][1025];
        memset(killed, 0, sizeof(killed));
        for (int i = 0; i < n; i++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            for (int j = x - d; j <= x + d;j++){
                if(0>j||j>1024){
                    continue;
                }
                for (int k = y - d; k <= y + d;k++){
                    if(0>k||k>1024){
                    continue;
                    }
                    killed[j][k] += z;
                }
            }
        }
        int ans = -1;
        int x, y;
        for (int i = 0; i < 1025; i++)
        {
            for (int j = 0; j < 1025;j++){
                if(killed[i][j]>ans){
                    ans = killed[i][j];
                    x = i;
                    y = j;
                }
            }
        }
        cout << x << " " << y << " " << ans<<'\n';
    }
}