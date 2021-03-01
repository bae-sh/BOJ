#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
using namespace std;
int p[3000];
int Find(int x){
    if(p[x]==x) return x;
    return p[x]=Find(p[x]);
}
void Union(int x,int y){
    x=Find(x);
    y=Find(y);
    p[x]=y;
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        int N; cin>>N;
        vector<pair<pair<int,int>,int>>v;
        set<int> s;
        
        for(int i=0;i<N;i++){
            int x,y,r; cin>>x>>y>>r;
            v.push_back({{x,y},r});
            p[i]=i;
        }
        for(int i=0;i<N;i++){
            for(int j=i+1;j<N;j++){
                int len=(int)pow((v[i].first.first-v[j].first.first),2)+(int)pow((v[i].first.second-v[j].first.second),2);
                if(len<=(int)pow(v[i].second+v[j].second,2)){//contact each other
                    Union(i, j);
                }
            }
        }
        for(int i=0;i<N;i++){
            s.insert(Find(i));
        }
        cout<<s.size()<<"\n";
        
    }
    return 0;
}
