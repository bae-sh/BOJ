#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1} ;
int num;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while (1)
    {
        int n; cin >> n;
        if(n==0)
            break;
        int cost[125][125];
        int ans[125][125];
        priority_queue<pair<int,pair<int, int>>> pq;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n;j++){
                cin>>cost[i][j];
                ans[i][j] = 987654321;
            }
        }
        ans[0][0] = cost[0][0];
        pq.push({-ans[0][0], {0, 0}});
        while(!pq.empty()){
            int curCost = -pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            for (int i = 0; i < 4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(0<=nx&&nx<n&&0<=ny&&ny<n){
                    if(ans[nx][ny]>cost[nx][ny]+curCost){
                        ans[nx][ny] = cost[nx][ny] + curCost;
                        pq.push({-ans[nx][ny], {nx, ny}});
                    }
                }
            }
        }
        cout << "Problem " << ++num << ": " << ans[n - 1][n - 1]<<"\n";
    }
}