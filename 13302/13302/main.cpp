#include <iostream>
#include <algorithm>
#include <queue>
#define INF 987654321
using namespace std;
int dp [101][101];//days,coupons
bool busy[101];
int N,M;
//bottom - up
/*void dfs(int days, int cost, int coupons){
    if(days>=N){
        ans=min(ans,cost);
        return;
    }
    
    if(busy[days+1]&&busy[days+2]&&busy[days+3]&&busy[days+4]&&busy[days+5]){
        if(!check[days+5][coupons]|| dp[days+5][coupons]>cost){
            check[days+5][coupons]=true;
            dp[days+5][coupons]=cost;
            dfs(days+5,cost,coupons);
        }
    }else{
        if(!check[days+5][coupons+2] || dp[days+5][coupons+2]>cost+37000){
            check[days+5][coupons+2]=true;
            dp[days+5][coupons+2]=cost+37000;
            dfs(days+5,cost+37000,coupons+2);
        }
    }
    
    if(busy[days+1]&&busy[days+2]&&busy[days+3]){
        if(!check[days+3][coupons] || dp[days+3][coupons]>cost){
            check[days+3][coupons] = true;
            dp[days+3][coupons]=cost;
            dfs(days+3,cost,coupons);
        }
    }else{
        if(!check[days+3][coupons+1] || dp[days+3][coupons+1]>cost+25000){
            check[days+3][coupons+1] =true;
            dp[days+3][coupons+1]=cost+25000;
            dfs(days+3,cost+25000,coupons+1);
        }
    }
    
    if(busy[days+1]){
        if(!check[days+1][coupons] || dp[days+1][coupons]>cost){
            check[days+1][coupons] =true;
            dp[days+1][coupons]=cost;
            dfs(days+1,cost,coupons);
        }
    }else{
        if(!check[days+1][coupons] || dp[days+1][coupons]>cost+10000){
            check[days+1][coupons] =true;
            dp[days+1][coupons]=cost+10000;
            dfs(days+1,cost+10000,coupons);
        }
        if(coupons>=3){
            if(!check[days+1][coupons-3] || dp[days+1][coupons-3]>cost){
                check[days+1][coupons-3] =true;
                dp[days+1][coupons-3]=cost;
                dfs(days+1,cost,coupons-3);
            }
        }
    }
}*/

//top -down
int go(int days, int coupons){
    if(days>N) return 0;
    if(dp[days][coupons]!=INF) return dp[days][coupons];
    if(busy[days]) return dp[days][coupons] = go(days+1,coupons);
    int &res = dp[days][coupons];
    res = min(res,go(days+5,coupons+2)+37000);
    res = min(res,go(days+3,coupons+1)+25000);
    res = min(res,go(days+1,coupons)+10000);
    if(coupons>=3){
        res = min(res,go(days+1,coupons-3));
    }
    return res;
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>N>>M;
    for(int i=0;i<M;i++){
        int x; cin>>x;
        busy[x]=true;
    }
    for(int i=0;i<101;i++){
        for(int j=0;j<101;j++){
            dp[i][j]=INF;
        }
    }
    cout<<go(1,0)<<"\n";
    return 0;
}
