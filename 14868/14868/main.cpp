#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int map[2001][2001];
int parent[100001];
int N,K, years;
int meet;
queue<pair<int,int>> q; //year, x, y
int find_parent(int x){
    if(parent[x] == x){
        return x;
    }
    return parent[x] = find_parent(parent[x]);
}
void Union(int x, int y){
    x = find_parent(x);
    y = find_parent(y);
    if(x!=y){
        parent[x]=y;
    }
}
bool UnionAll(){
    int size = (int)q.size();
    for(int i=0;i<size;i++){
        int x=q.front().first; int y=q.front().second; q.pop(); q.push({x,y});
        for(int i=0;i<4;i++){
            int nx=x+dx[i]; int ny=y+dy[i];
            if(0<nx&&nx<=N&&0<ny&&ny<=N){
                int p = find_parent(map[x][y]);
                int np = find_parent(map[nx][ny]);
                if(np!=0&&p!=np){
                    Union(p, np);
                    meet++;
                }
            }
        }
    }
    if(K>meet+1){
        return false;
    }else{
        return true;
    }
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>N>>K;
    for(int i=1;i<=K;i++){
        int x, y; cin>>x>>y;
        map[x][y]=i;
        parent[i]=i;
        q.push({x,y});
    }
    
    while(!UnionAll()){
        int size = (int)q.size();
        for(int i=0;i<size;i++){
            int x=q.front().first; int y=q.front().second; q.pop();
            int p = find_parent(map[x][y]);
            for(int i=0;i<4;i++){
                int nx=x+dx[i]; int ny=y+dy[i];
                if(0<nx&&nx<=N&&0<ny&&ny<=N){
                    if(map[nx][ny]==0){
                        map[nx][ny]=p;
                        q.push({nx,ny});
                    }
                }
            }
        }
        years++;
    }
    cout<<years<<"\n";
    return 0;
}
