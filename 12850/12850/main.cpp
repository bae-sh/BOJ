#include <iostream>
#include <vector>
#include <string.h>
#define Mod 1000000007
using namespace std;
typedef vector<vector<long long>> matrix;
matrix operator * (const matrix& a, const matrix& b){
    matrix c(8,vector<long long>(8));
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            for(int k=0;k<8;k++){
                c[i][j]+=a[i][k]*b[k][j];
            }
            c[i][j]%=Mod;
        }
    }
    return c;
}
long long D;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin>>D;
    matrix dp(8,vector<long long>(8));
    matrix ans(8,vector<long long>(8));
    for(int i=0;i<8;i++){
        ans[i][i]=1;
    }
    
    dp[0][1]=dp[1][0]=dp[0][2]=dp[2][0]=1;
    dp[1][2]=dp[2][1]=dp[1][3]=dp[3][1]=1;
    dp[2][3]=dp[3][2]=dp[2][4]=dp[4][2]=1;
    dp[3][4]=dp[4][3]=dp[3][5]=dp[5][3]=1;
    dp[4][5]=dp[5][4]=dp[4][7]=dp[7][4]=1;
    dp[5][6]=dp[6][5]=dp[6][7]=dp[7][6]=1;
    while(D>0){
        if(D&1){
            ans = ans * dp;
        }
        dp= dp*dp;
        D=(D>>1);
    }
    cout<<ans[0][0]<<"\n";
    return 0;
}
