#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 987654321;
using namespace std;
int N,M,X,Y;
vector<pair<int,int>> v[1000];
int cost[1000];
int ans=1;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
    cin>>N>>M>>X>>Y;
    for(int i=0;i<M;i++){
        int from,to,dis; cin>>from>>to>>dis;
        v[from].push_back({to,dis});
        v[to].push_back({from,dis});
    }
    for(int i=0;i<1000;i++){
        cost[i]=MAX;
    }
    cost[Y]=0;
    priority_queue<pair<int,int>> pq;
    pq.push({0,Y});
    while(!pq.empty()){
        int curCost = -pq.top().first;
        int curPos=pq.top().second; pq.pop();
        for(int i=0;i<v[curPos].size();i++){
            int nextPos=v[curPos][i].first;
            int nextCost=v[curPos][i].second;
            if(curCost+nextCost<cost[nextPos]){
                cost[nextPos]=curCost+nextCost;
                pq.push({-cost[nextPos],nextPos});
            }
        }
    }
    
    sort(cost,cost+N);
    
    int curCost=0;
    for(int i=0;i<N;i++){
        if(cost[i]*2+curCost<=X){
            curCost+=2*cost[i];
        }else{
            if(cost[i]*2>X){
                ans=-1;
                break;
            }
            curCost=cost[i]*2;
            ans++;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
