#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
int N,M;
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};
int Map[1000][1000];
int dp[1000][1000];
map<int,int> area;
int ans[1000][1000];
void dfs(int x,int y,int color){
    Map[x][y]=color;
    area[color]++;
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(0<=nx&&nx<N&&0<=ny&&ny<M){
            if(Map[nx][ny]==0){
                dfs(nx,ny,color);
            }
        }
    }
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            char x; cin>>x;
            Map[i][j]=(x-'0');
        }
    }
    int color =2;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(Map[i][j]==0){
                dfs(i,j,color);
                color++;
            }
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(Map[i][j]==1){
                set<int> s;
                ans[i][j]++;
                for(int k=0;k<4;k++){
                    int nx= i+dx[k];
                    int ny= j+dy[k];
                    if(0<=nx&&nx<N&&0<=ny&&ny<M){
                        if(s.count(Map[nx][ny])!=1){
                            s.insert(Map[nx][ny]);
                            ans[i][j]+=area[Map[nx][ny]];
                        }
                    }
                }
            }
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cout<<ans[i][j]%10;
        }
        cout<<"\n";
    }
    return 0;
}
