#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define Max 987654321
using namespace std;
int cost[100001];
int N, start_robot, end_robot;
vector<pair<int,int>> v[100001]; // next, cost
int max_cost[100001];//from start to end
priority_queue<pair<int,int>> pq;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(0); cin.tie(0);
    
    cin>>N>>start_robot>>end_robot;
    for(int i=1;i<100001;i++){
        cost[i]=Max;
    }
    cost[start_robot] = 0;
    for(int i=0;i<N-1;i++){
        int s,e,c; cin>>s>>e>>c;
        v[s].push_back({e,c});
        v[e].push_back({s,c});
    }
    pq.push({0,start_robot});
    while(!pq.empty()){
        int cur = pq.top().second;
        int cCost = -pq.top().first; pq.pop();
        
        for(int i=0;i<v[cur].size();i++){
            int next = v[cur][i].first;
            int nCost = v[cur][i].second;
            
            if(cCost + nCost < cost[next]){
                cost[next]=cCost + nCost;
                pq.push({-cost[next],next});
                if(max_cost[next]<nCost){
                    max_cost[next] = nCost;
                }
                if(max_cost[next]<max_cost[cur]){
                    max_cost[next] = max_cost[cur];
                }
            }
        }
    }
    cout<<cost[end_robot]-max_cost[end_robot]<<"\n";
    return 0;
}
