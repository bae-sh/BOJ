#include <iostream>
#include <map>
using namespace std;
int N,S;
long long ans;
int num[41];
map<int,int> m;
void left_dfs(int idx, int sum){
    if(idx == N/2){
        m[sum]++;
        return;
    }
    left_dfs(idx+1, sum);
    left_dfs(idx+1, sum+num[idx]);
}
void right_dfs(int idx, int sum){
    if(idx == N){
        ans+=m[S-sum];
        return;
    }
    right_dfs(idx+1, sum);
    right_dfs(idx+1, sum+num[idx]);
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>N>>S;
    for(int i=0;i<N;i++){
        cin>>num[i];
    }
    left_dfs(0, 0);
    right_dfs(N/2, 0);
    if(S==0) ans--;
    cout<<ans<<"\n";
    return 0;
}
