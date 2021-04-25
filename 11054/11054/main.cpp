#include <iostream>
#include <algorithm>
using namespace std;

int N;
int a[1000];
int dp[1000][2];
int ans;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>a[i];
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<2;j++){
            dp[i][j]=1;
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<i;j++){
            if(a[j]<a[i]){
                dp[i][0]=max(dp[i][0],dp[j][0]+1);
            }
        }
    }
    for(int i=N-1;i>=0;i--){
        for(int j=N-1;j>i;j--){
            if(a[j]<a[i] && dp[j][1]>=dp[i][1]){
                dp[i][1]=max(dp[i][1],dp[j][1]+1);
            }
        }
    }
    for(int i=0;i<N;i++){
        ans=max(ans,dp[i][0]+dp[i][1]-1);
    }
    cout<<ans<<"\n";
    return 0;
}
