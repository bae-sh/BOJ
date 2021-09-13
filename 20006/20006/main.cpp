#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <math.h>
using namespace std;

int p,m;
vector<pair<string,int>> v[300]; // name,level

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>p>>m;
    for(int i=0;i<p;i++){
        int level; cin>>level;
        string name; cin>>name;
        for(int j=0;j<300;j++){
            if(v[j].size()==0){
                v[j].push_back({name,level});
                break;
            }else if(v[j].size()<m){
                if(abs(v[j][0].second-level)<=10){
                    v[j].push_back({name,level});
                    break;
                }
            }
        }
    }
    for(int i=0;i<300;i++){
        sort(v[i].begin(),v[i].end());
        if(v[i].size()==m){
            cout<<"Started!\n";
        }else if(v[i].size()>0){
            cout<<"Waiting!\n";
        }
        for(int j=0;j<v[i].size();j++){
            cout<<v[i][j].second<<" "<<v[i][j].first<<"\n";
        }
    }
    return 0;
}
