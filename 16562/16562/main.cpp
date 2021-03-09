#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int N,M,k;
int parent[10001];
int cost[10001];
set <int> Friend;
int allCost;
int find(int x){
    if(parent[x]==x) return x;
    return parent[x]=find(parent[x]);
}
void Union(int x,int y){
    x=find(x);
    y=find(y);
    if(cost[x]<cost[y]){
        parent[y]=x;
    }else{
        parent[x]=y;
    }
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>N>>M>>k;
    for(int i=1;i<=N;i++){
        parent[i]=i;
        int c; cin>>c;
        cost[i]=c;
    }
    for(int i=0;i<M;i++){
        int x,y; cin>>x>>y;
        Union(x, y);
    }
    for(int i=1;i<=N;i++){
        int p =find(i);
        if(Friend.count(p)==0){
            allCost+=cost[p];
            Friend.insert(p);
        }
    }
    if(k<allCost){
        cout<<"Oh no\n";
    }else{
        cout<<allCost<<"\n";
    }
    return 0;
}
