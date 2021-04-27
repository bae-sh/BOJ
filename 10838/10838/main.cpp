#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string.h>
using namespace std;
int N,K,cnt;
int parent[100001];
int color[100001];
int temp[100001];
int Lca(int a, int b){
    cnt++;
    while(1){
        if(temp[a]==cnt && a) return a;
        if(temp[b]==cnt && b) return b;
        temp[a]=cnt; temp[b]=cnt;
        if(a==b) return a;
        a=parent[a]; b=parent[b];
    }
}

void paint(int a, int b, int c){
    int lca = Lca(a,b);
    while(a!=lca){
        color[a]=c;
        a=parent[a];
    }
    while(b!=lca){
        color[b]=c;
        b=parent[b];
    }
}

int Count(int a, int b){
    set<int> s;
    int lca = Lca(a,b);
    while(a!=lca){
        s.insert(color[a]);
        a=parent[a];
    }
    while(b!=lca){
        s.insert(color[b]);
        b=parent[b];
    }
    return (int)s.size();
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>N>>K;
    for(int i=0;i<K;i++){
        int r,a,b,c; cin>>r>>a>>b;
        if(r==1){
            cin>>c;
            paint(a, b, c);
        }else if(r==2){
            parent[a]=b;
        }else{
            cout<<Count(a,b)<<"\n";
        }
    }
    return 0;
    
}
