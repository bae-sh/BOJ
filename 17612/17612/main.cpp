#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int N,K;
vector<pair<int,int>> person;
priority_queue<pair<int,int>> pq; // 대기시간,위치,
priority_queue<pair<int,pair<int,int>>> order;
long long ans;
long long cnt;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>N>>K;
    for(int i=0;i<N;i++){
        int x,y; cin>>x>>y;
        person.push_back({x,y});
    }
    for(int i=0;i<K;i++){
        pq.push({0,-i});
    }
    for(int i=0;i<person.size();i++){
        int id = person[i].first;
        int delayed = person[i].second;
        
        int passTime = -pq.top().first;
        int num = -pq.top().second; pq.pop();
        order.push({-(passTime+delayed),{num,id}});
        pq.push({-(passTime+delayed),-num});
    }
    while (!order.empty()) {
        long long pre_id = order.top().second.second; order.pop();
        cnt++;
        ans+=cnt*pre_id;
    }
    cout<< ans<<"\n";
    return 0;
}
