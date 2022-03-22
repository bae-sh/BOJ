#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N, R, Q;
bool check[100001];
int cnt[100001];
vector<int> v[100001];

int dfs(int x){
    if(check[x]){
        return cnt[x];
    }
    cnt[x] = 1;
    check[x] = true;
    for (int cur : v[x])
    {
        if(!check[cur]){
            cnt[x] += dfs(cur);
        }
    }
    return cnt[x];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> R >> Q;

    for (int i = 0; i < N-1;i++){
        int x,y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    dfs(R);
        for (int i = 0; i < Q; i++)
        {
            int x;
            cin >> x;
            cout << cnt[x] << "\n";
        }
}