#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int map[101];
int moveTo[101];
bool check[101];
int N,M;
queue<pair<int,int>> q; // pos,cnt
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>N>>M;
    for(int i=0;i<N+M;i++){
        int x,y; cin>>x>>y;
        moveTo[x]=y;
    }
    q.push({1,0});
    while(!q.empty()){
        int pos = q.front().first;
        int cnt = q.front().second; q.pop();
        check[pos] = true;
        if(pos==100){
            cout<<cnt<<"\n";
            break;
        }
        if(moveTo[pos]){
            pos=moveTo[pos];
        }
        for(int i=1;i<7;i++){
            if(pos+i<=100&&!check[pos+i]){
                q.push({pos+i,cnt+1});
            }
        }
    }
    return 0;
}
