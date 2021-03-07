#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    double X, Y, D, T; cin>>X>>Y>>D>>T;
    double ans=0;
    double distance = sqrt((X*X)+(Y*Y));
    while(1){
        if(distance>D*2){
            if(D<=T){
                ans=distance;
                break;
            }else{
                distance-=D;
                ans+=T;
            }
        }else{
            ans += min(min(distance,T*2), T+abs(distance-D));
            break;
        }
    }
    printf("%.9lf",ans);
    return 0;
}
