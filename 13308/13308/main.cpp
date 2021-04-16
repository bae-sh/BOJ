#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 10100987654321
using namespace std;
int N,M;
int oilPrice[2501];
vector<pair<long long,int>> cost[2501];// cost, min_oilcost
vector<pair<int,int>> v[2501];
priority_queue<pair<long long,pair<int,int>>> pq; // cur_cost, oil_cost,cur_pos
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        int x; cin>>x;
        oilPrice[i] = x;
        cost[i].push_back({MAX,MAX});
    }
    for(int i=0;i<M;i++){
        int a,b,c; cin>>a>>b>>c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    cost[1].front().first=0;
    cost[1].front().second=oilPrice[1];
    pq.push({-cost[1].front().first,{-oilPrice[1],1}});
    while(!pq.empty()){
        long long cur_cost = -pq.top().first;
        int oil_cost = -pq.top().second.first;
        int cur = pq.top().second.second; pq.pop();
        for(int i=0;i<v[cur].size();i++){
            int next = v[cur][i].first;
            long long nCost = v[cur][i].second*oil_cost;
            bool go = true;
            for(int j=0;j<cost[next].size();j++){
                if(cur_cost+nCost>=cost[next][j].first&&oil_cost>=cost[next][j].second){
                    go = false;
                    break;
                }
            }
            if(go){
                cost[next].push_back({cur_cost+nCost,min(oil_cost,oilPrice[next])});
                if(next!=N){
                    pq.push({-(cur_cost+nCost),{-min(oil_cost,oilPrice[next]),next}});
                }
            }
        }
    }
    for(int i=1;i<cost[N].size();i++){
        if(cost[N][0].first>cost[N][i].first){
            cost[N][0].first=cost[N][i].first;
        }
    }
    cout<<cost[N][0].first<<"\n";
}
