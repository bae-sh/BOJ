#include<iostream>
#include<algorithm>
#include<string.h>
#define MAX 4000000
using namespace std;

int R,C;
char MAP[10000][500];
bool visit[10000][500];
int dx[]={-1,0,1};
int ans;

bool dfs(int x,int y){
    if(y==C-1){
        MAP[x][y]='x';
        return true;
    }
    for(int i=0;i<3;i++){
        int nx=x+dx[i];
        int ny=y+1;
        if(0<=nx&&nx<R&&0<=ny&&ny<C){
            if(!visit[nx][ny] && MAP[nx][ny]=='.'){
                visit[nx][ny]=true;
                if(dfs(nx,ny)){
                    MAP[x][y]='x';
                    return true;
                }
            }
        }
    }
    return false;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin>>R>>C;
    for(int i=0;i<R;i++){
        string s; cin>>s;
        for(int j=0;j<C;j++){
            MAP[i][j]=s[j];
        }
    }
    for(int i=0;i<R;i++){
        if(dfs(i,0)){
            ans++;
        }
    }
    cout<<ans<<"\n";
}
