#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int p[100001];
vector<int> plane;
int G,P,ans;
int find_parent(int x){
    if(p[x]==x) return x;
    else return p[x]=find_parent(p[x]);
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
   
    cin>>G>>P;
    for(int i=1;i<=G;i++){
        p[i]=i;
    }
    for(int i=0;i<P;i++){
        int p; cin>>p;
        plane.push_back(p);
    }
    for(int i=0;i<plane.size();i++){
        int cur_plane=plane[i];
        int parent=find_parent(cur_plane);
        if(parent==0){
            break;
        }else{
            p[parent]=parent-1;
            ans++;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
