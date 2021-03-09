#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
using namespace std;
set <pair<int,int>> s;
int ans;
int ccw(pair<long long,long long> p1, pair<long long,long long> p2, pair<long long, long long> p3){
    long long res = (p2.first-p1.first)*(p3.second-p1.second)-(p2.second-p1.second)*(p3.first-p1.first);
    if(res>0) return 1;
    else if(res<0) return -1;
    else return 0;
}
int intersect(pair<long long,long long> p1, pair<long long,long long> p2, pair<long long, long long> p3, pair<long long, long long> p4){
    int ccw1 = ccw(p1,p2,p3);
    int ccw2 = ccw(p1,p2,p4);
    int ccw3 = ccw(p3,p4,p1);
    int ccw4 = ccw(p3,p4,p2);
    if(ccw1==0&&ccw2==0&&ccw3==0&&ccw4==0){//모두 한직선
        if(p1>p2){
            swap(p1,p2);
        }
        if(p3>p4){
            swap(p3, p4);
        }
        if(p1<=p4&&p2>=p3){//겹치는 부분
            if(p2==p3){
                if(s.count(p2)==0){
                    s.insert(p2);
                    return 1;
                }else{
                    return 0;
                }
            }else if(p1==p4){
                if(s.count(p1)==0){
                    s.insert(p1);
                    return 1;
                }else{
                    return 0;
                }
            }
            else{
                return 4;
            }
        }else{
            return 0;// 떨어져 있는부분
        }
    }
    if(ccw1 * ccw2 ==0 && ccw3 * ccw4 ==0){
        if(p1==p3||p1==p4){
            if(s.count(p1)==0){
                s.insert(p1);
                return 1;
            }else{
                return 0;
            }
        }else if(p2==p3||p2==p4){
            if(s.count(p2)==0){
                s.insert(p2);
                return 1;
            }else{
                return 0;
            }
        }
        else{
            return 0;
        }
    }
    else if(ccw1 * ccw2 <=0 && ccw3 * ccw4 <=0){
        if((p3.second-p1.second)*(p4.first-p3.first)==(p4.second-p3.second)*(p3.first-p1.first)){//꼭지점에서 만날때
            if(s.count(p1)==0){
                s.insert(p1);
                return 1;
            }else{
                return 0;
            }
        }else if((p3.second-p2.second)*(p4.first-p3.first)==(p4.second-p3.second)*(p3.first-p2.first)){//꼭지점에서 만날때
            if(s.count(p2)==0){
                s.insert(p2);
                return 1;
            }else{
                return 0;
            }
        }else{//선분에서 만날때
            return 1;
        }
    }else{
        return 0;//안만나는부분
    }
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T; cin>>T;
    while(T--){
        vector<pair<long long,long long>> recLine;
        s.clear();
        ans = 0;
        long long xmin,ymin,xmax,ymax; cin>>xmin>>ymin>>xmax>>ymax;
        long long x1,y1,x2,y2; cin>>x1>>y1>>x2>>y2;
        
        recLine.push_back({xmin,ymin}); recLine.push_back({xmin,ymax}); recLine.push_back({xmax,ymax}); recLine.push_back({xmax,ymin});
        for(int i=0;i<4;i++){
            ans+=intersect(recLine[i], recLine[(i+1)%4], {x1,y1}, {x2,y2});
        }
        if(ans>4){
            cout<<"4\n";
        }else{
            cout<<ans<<"\n";
        }
    }
    return 0;
}

