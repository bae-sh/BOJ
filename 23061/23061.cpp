#include<iostream>
#include<algorithm>
#include<vector>
#define MAX 1000001
using namespace std;
int N, M;
int ans[101][MAX];
double maxValue;
int num=1;
vector<pair<int, int>> list;
vector<int> bag;
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N;i++){
        int x, y; cin>>x>>y;
        list.push_back({x, y});
    }
    for (int i = 0; i < M;i++){
        int x; cin>>x;
        bag.push_back(x);
    }
    for (int i = 0; i < N; i++)
    {
        int w = list[i].first;
        int v = list[i].second;
        for (int j = 0; j < MAX; j++)
        {
            if (w <= j)
            {
                ans[i + 1][j] = max(ans[i][j], ans[i][j - w] + v);
            }
            else
            {
                ans[i + 1][j] = ans[i][j];
            }
        }
    }
    for (int i = 1; i < MAX;i++){
        ans[N][i] = max(ans[N][i], ans[N][i - 1]);
    }
    for (int i = 0; i < M;i++){
        int w = bag[i];
        double curValue = ans[N][w]*1.0 / w;
        if(curValue>maxValue){
            maxValue=curValue;
            num = i + 1;
        }
    }
    cout << num << '\n';
}
