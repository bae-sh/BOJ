#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>
using namespace std;
int T,F;
int order;
map<string,int> m;
int parent[300001];
int group[300001];
int find_parent(int x){
    if(parent[x]==x) return x;
    return parent[x]=find_parent(parent[x]);
}
int Union(int x,int y){
    x = find_parent(x);
    y = find_parent(y);
    if(x == y){
        return group[x];
    }else{
        parent[y]=x;
        group[x]+=group[y];
        return group[x];
    }
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>T;
    while(T--){
        cin>>F;
        order=1;
        for(int i=1;i<=300000;i++){
            parent[i]=i;
            group[i]=1;
        }
        for(int i=0;i<F;i++){
            string a,b; cin>>a>>b;
            if(m[a]==0){
                m[a]=order;
                order++;
            }
            if(m[b]==0){
                m[b]=order;
                order++;
            }
            cout<<Union(m[a], m[b])<<"\n";
        }
    }
    return 0;
}
