#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;

int L,R,C;
int sf,sx,sy;
int df[]={0,0,0,0,1,-1};
int dx[]={-1,0,1,0,0,0};
int dy[]={0,1,0,-1,0,0};

int bfs(char MAP[30][30][30], int dp[30][30][30]){
    queue<pair<int,pair<int,int>>> q;
    q.push({sf,{sx,sy}});
    while (!q.empty())
    {
        int floor = q.front().first;
        int x = q.front().second.first;
        int y= q.front().second.second; q.pop();
        
        for (int i = 0; i < 6; i++)
        {
            int nf=floor +df[i];
            int nx=x+dx[i];
            int ny=y+dy[i];

            if(0<=nf&&nf<L&&0<=nx&&nx<R&&0<=ny&&ny<C){
                if(MAP[nf][nx][ny]=='.' && dp[nf][nx][ny]==0){
                    dp[nf][nx][ny]=dp[floor][x][y]+1;
                    q.push({nf,{nx,ny}});
                }else if(MAP[nf][nx][ny]=='E'){
                    return dp[floor][x][y]+1;
                }
            }
        }
    }
    return -1;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    while(true){

        cin>>L>>R>>C;
        if(L==0&&R==0&&C==0){
            break;
        }

        char MAP[30][30][30]; // 층,행,열
        int dp[30][30][30];

        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < L; i++)
        {
            for(int j=0;j<R;j++){
                string s; cin>>s;
                for(int k=0;k<C;k++){
                    MAP[i][j][k]=s[k];
                    if(s[k]=='S'){
                        sf=i;
                        sx=j;
                        sy=k;
                    }
                }
            }
        }

        int ans = bfs(MAP,dp);

        if(ans==-1){
            cout<<"Trapped!\n";
        }else{
            cout<<"Escaped in "<<ans<<" minute(s).\n";
        }
    }
}