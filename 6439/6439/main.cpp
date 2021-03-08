#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int ccw(pair<long long,long long> p1, pair<long long,long long> p2, pair<long long, long long> p3){
    long long res = (p2.first-p1.first)*(p3.second-p1.second)-(p2.second-p1.second)*(p3.first-p1.first);
    if(res>0) return 1;
    else if(res<0) return -1;
    else return 0;
}
bool intersect(pair<long long,long long> p1, pair<long long,long long> p2, pair<long long, long long> p3, pair<long long, long long> p4){
    int ccw1 = ccw(p1,p2,p3);
    int ccw2 = ccw(p1,p2,p4);
    int ccw3 = ccw(p3,p4,p1);
    int ccw4 = ccw(p3,p4,p2);
    if(ccw1 * ccw2 ==0 && ccw3 * ccw4 ==0){
        if(p1>p2){
            swap(p1,p2);
        }
        if(p3>p4){
            swap(p3, p4);
        }
        if(p1<=p4&&p2>=p3){
            return true;
        }else{
            return false;
        }
    }
    else if(ccw1 * ccw2 <=0 && ccw3 * ccw4 <=0){
        return true;
    }else{
        return false;
    }
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T; cin>>T;
    while(T--){
        vector<pair<long long,long long>> v;
        bool cross = false;
        for(int i=0;i<2;i++){
            int x, y; cin>>x>>y;
            v.push_back({x,y});
        }
        int x1,y1,x2,y2; cin>>x1>>y1>>x2>>y2;
        if(x1>x2){
            swap(x1,x2);
        }
        if(y1<y2){
            swap(y1, y2);
        }
        if(x1<v[0].first&&v[0].first<x2&&y2<v[0].second&&v[0].second<y1){
            cross=true;
        }else if(x1<v[1].first&&v[1].first<x2&&y2<v[1].second&&v[1].second<y1){
            cross=true;
        }else{
            v.push_back({x1,y1}); v.push_back({x1,y2}); v.push_back({x2,y2}); v.push_back({x2,y1});
            cross=intersect(v[0], v[1], v[2], v[3])|intersect(v[0], v[1], v[3], v[4])|intersect(v[0], v[1], v[4], v[5])|intersect(v[0], v[1], v[2], v[5]);
        }
        if(cross){
            cout<<"T\n";
        }else{
            cout<<"F\n";
        }
    }
    return 0;
}
