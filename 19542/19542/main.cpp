#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v[100001];
bool visited[100001];
int N,S,D;
int ans;
int dfs(int start){
    int max_len=0;
    visited[start]=true;
    
    for(int i=0;i<v[start].size();i++){
        int next=v[start][i];
        if(!visited[next]){
            int temp=dfs(next);
            if(temp>=D){
                ans+=2;
            }
            max_len=max(max_len,temp+1);
        }
    }
    return max_len;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>N>>S>>D;
    for(int i=0;i<N-1;i++){
        int x,y; cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(S);
    cout<<ans<<"\n";
}
