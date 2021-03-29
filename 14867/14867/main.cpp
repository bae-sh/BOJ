#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
int a,b,c,d;
map <pair<int,int>,int> m;
queue<pair<pair<int,int>,int>> q;
int ans = -1;

void Full(int x,int y, int cost) {
    if(m.count({x,y})==0){
        q.push({{x,y},cost+1});
        m.insert({{x,y},cost+1});
    }
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>a>>b>>c>>d;
    q.push({{0,0},0});
    m.insert({{0,0},0});
    while(!q.empty()){
        int cur_a = q.front().first.first;
        int cur_b = q.front().first.second;
        int cost = q.front().second; q.pop();
        
        if(cur_a==c&&cur_b==d){
            ans=cost;
            break;
        }
        //F(a)
        int na=a; int nb=cur_b;
        Full(na,nb,cost);
        //F(b)
        na = cur_a; nb = b;
        Full(na,nb,cost);
        //M(b,a)
        na = cur_a + cur_b;
        if(na>a){
            nb = na - a;
            na = a;
        }else{
            nb = 0;
        }
        Full(na,nb,cost);
        //M(a,b)
        nb = cur_a + cur_b;
        if(nb>b){
            na = nb - b;
            nb = b;
        }else{
            na=0;
        }
        Full(na,nb,cost);
        //E(a)
        na = 0 ; nb =cur_b;
        Full(na, nb,cost);
        //E(b)
        na = cur_a; nb= 0;
        Full(na,nb, cost);
    }
    cout<<ans<<"\n";
    return 0;
}
