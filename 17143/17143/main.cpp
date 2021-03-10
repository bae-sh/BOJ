#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
struct shark{
    int speed,way,size;
};
int R,C,M;
shark map[101][101];
shark next_map[101][101];
int ans;
pair<int,int> move (int way, int pos,int len,int speed){
    for(int i=1;i<=speed;i++){
        int npos=pos+way;
        if(npos<1){
            way=1;
            pos=2;
        }else if(npos>len){
            way=-1;
            pos=len-1;
        }else{
            pos = npos;
        }
    }
    return {way,pos};
}
int fishing(int cur_num){
    for(int i=1;i<=R;i++){
        int size=map[i][cur_num].size;
        if(size!=0){
            map[i][cur_num].size=0;
            return size;
        }
    }
    return 0;
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>R>>C>>M;
    for(int i=0;i<M;i++){
        shark sk;
        int x,y;cin>>x>>y>>sk.speed>>sk.way>>sk.size;
        if(sk.way==1||sk.way==2){
            sk.speed%=(2*(R-1));
        }else{
            sk.speed%=(2*(C-1));
        }
        map[x][y]=sk;
    }
    for(int k=1;k<=C;k++){
        ans += fishing(k);
        for(int i=1;i<=R;i++){
            for(int j=1;j<=C;j++){
                shark &cur_shark = map[i][j];
                if(cur_shark.size!=0){
                    int nx=i; int ny=j;
                    pair<int,int> p;
                    switch (cur_shark.way) {
                        case 1:
                            p=move(-1, i, R, cur_shark.speed);
                            nx=p.second;
                            cur_shark.way= p.first == -1 ? 1: 2;
                            break;
                        case 2:
                            p=move(1, i, R, cur_shark.speed);
                            nx=p.second;
                            cur_shark.way= p.first == -1 ? 1: 2;
                            break;
                        case 3:
                            p=move(1, j, C, cur_shark.speed);
                            ny=p.second;
                            cur_shark.way=p.first == 1 ? 3 : 4;
                            break;
                        case 4:
                            p=move(-1, j, C, cur_shark.speed);
                            ny=p.second;
                            cur_shark.way=p.first == 1 ? 3 : 4;
                            break;
                    }
                    if(next_map[nx][ny].size<cur_shark.size){
                        next_map[nx][ny]=cur_shark;
                    }
                }
            }
        }
        memcpy(map, next_map, sizeof(map));
        memset(next_map, 0, sizeof(next_map));
    }
    cout<<ans<<"\n";
    return 0;
}
