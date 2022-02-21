#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;

int N,M,ans;
vector<int> person[101];
int notebook[101];
bool visit[101];

bool matching(int idx){
    for(int i=0;i<person[idx].size();i++){
        int noteNum = person[idx][i];

        if(visit[noteNum]) continue;
        visit[noteNum] = true;

        if(notebook[noteNum]==0 || matching(notebook[noteNum])){
            notebook[noteNum]= idx;
            return true;
        }
    }
    return false;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin>>N>>M;
    for(int i=0;i<M;i++){
        int a,b; cin>>a>>b;
        person[a].push_back(b);
    }
    
    for(int i=1;i<=N;i++){
        memset(visit,0,sizeof(visit));
        if(matching(i)){
            ans++;
        }
    }

    cout<<ans<<"\n";
}