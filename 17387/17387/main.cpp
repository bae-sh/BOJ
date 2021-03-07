#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<pair<long long,long long>> v;
int ccw(pair<long long,long long> p1, pair<long long,long long> p2, pair<long long, long long> p3){
    long long res = (p2.first-p1.first)*(p3.second-p1.second)-(p2.second-p1.second)*(p3.first-p1.first);
    if(res>0) return 1;
    else if(res<0) return -1;
    else return 0;
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    for(int i=0;i<4;i++){
        long long x, y; cin>>x>>y;
        v.push_back({x,y});
    }
    int ccw1 = ccw(v[0],v[1],v[2]);
    int ccw2 = ccw(v[0],v[1],v[3]);
    int ccw3 = ccw(v[2],v[3],v[0]);
    int ccw4 = ccw(v[2],v[3],v[1]);
    if(ccw1 * ccw2 ==0 && ccw3 * ccw4 ==0){
        if(v[0]>v[1]){
            swap(v[0],v[1]);
        }
        if(v[2]>v[3]){
            swap(v[2], v[3]);
        }
        if(v[0]>v[2]){
            swap(v[0], v[2]);
            swap(v[1], v[3]);
        }
        if(v[0]<=v[3]&&v[1]>=v[2]){
            cout<<"1\n";
        }else{
            cout<<"0\n";
        }
    }
    else if(ccw1 * ccw2 <=0 && ccw3 * ccw4 <=0){
        cout<<"1\n";
    }else{
        cout<<"0\n";
    }
    return 0;
}
