#include <iostream>
#include <algorithm>
using namespace std;

int a[301][301];
int sum[301][301];
int n;
int ans=-987654321;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            sum[i][j]=a[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
        }
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                int tempAns=sum[i][j]-sum[i-k][j]-sum[i][j-k]+sum[i-k][j-k];
                ans=max(tempAns,ans);
                if(i-k==0||j-k==0) break;
            }
        }
    }
    cout<<ans<<'\n';
    return 0;
}
