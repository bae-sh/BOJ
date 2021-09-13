#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
int M,N,P;
char field[1000][1000];
int userHp[26];
int arrivedTime[26];
int bossHp;
vector<pair<int,int>> userP[26];
bool check[26];

int bfs(int x,int y){
    queue<pair<pair<int,int>,int>> q;
    q.push({{x,y},0});
    bool cost[1000][1000];
    for(int i=0;i<1000;i++){
        for(int j=0;j<1000;j++){
            cost[i][j]=false;
        }
    }
    while(!q.empty()){
        int curX= q.front().first.first;
        int curY=q.front().first.second;
        int curTime=q.front().second; q.pop();
        
        for(int i=0;i<4;i++){
            int nx=curX+dx[i];
            int ny=curY+dy[i];
            if(0<=nx&&nx<M&&0<=ny&&ny<N){
                if(field[nx][ny]!='X'){
                    if(field[nx][ny]=='B'){
                        return curTime+1;
                    }else{
                        if(!cost[nx][ny] || cost[nx][ny]>=curTime+1){
                            cost[nx][ny]=true;
                            q.push({{nx,ny},curTime+1});
                        }
                    }
                }
            }
        }
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>M>>N>>P;
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            cin>>field[i][j];
            if('a'<=field[i][j]&&field[i][j]<='z'){
                userP[field[i][j]-'a'].push_back({i,j});
            }
        }
    }
    for(int i=0;i<P;i++){
        char c; cin>>c;
        cin>>userHp[c-'a'];
    }
    cin>>bossHp;
    
    for(int i=0;i<26;i++){
        if(userHp[i]!=0){
            int x= userP[i][0].first;
            int y=userP[i][0].second;
            arrivedTime[i]=bfs(x, y);
        }
    }
    int time=0;
    int answer=0;
    while(++time){
        for(int i=0;i<26;i++){
            if(arrivedTime[i]!=0&&arrivedTime[i]<time){
                bossHp-=userHp[i];
                if(!check[i]){
                    check[i]=true;
                    answer++;
                }
            }
        }
        if(bossHp<=0){
            cout<<answer<<"\n";
            break;
        }
    }
    return 0;
}
