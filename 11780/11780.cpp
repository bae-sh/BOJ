#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#define MAX 987654321
using namespace std;

int n,m;
int MAP[101][101];
int trace[101][101];
vector<int> v;
void dfs(int start,int end){
    if(trace[start][end]==0){
        v.push_back(start);
        v.push_back(end);
        return;
    }
    dfs(start,trace[start][end]);
    v.pop_back();
    dfs(trace[start][end],end);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            MAP[i][j]=MAX;
        }
        MAP[i][i]=0;
    }
    for(int i=0;i<m;i++){
        int x,y,z; cin>>x>>y>>z;
        MAP[x][y]=min(MAP[x][y],z);
    }

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(MAP[i][j]>MAP[i][k]+MAP[k][j]){
                    MAP[i][j]=MAP[i][k]+MAP[k][j];
                    trace[i][j]=k;
                }
            }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(MAP[i][j]==MAX){
                cout<<"0 ";
            }else{
                cout<<MAP[i][j]<<" ";
            }
        }
        cout<<"\n";
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j || MAP[i][j]==MAX){
                cout<<"0";
            }else{
                v.clear();
                dfs(i,j);
                cout<<v.size()<<" ";
                for(int k=0;k<v.size();k++){
                    cout<<v[k]<<" ";
                }
            }
            cout<<"\n";
        }
    }
}