#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
bool ans = false;
vector<pair<long long,long long>> v;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>N;
    for(int i=0;i<=N;i++){
        long long x,y; cin>>x>>y;
        v.push_back({x,y});
    }
    
    int left=0,right=0,up=0, down=0;
    for(int i=0;i<N;i++){
        long long x = v[N].first-v[i].first;
        long long y= v[N].second-v[i].second;
        if(x>0&&x>=abs(y))left++;
        if(x<0&&abs(x)>=abs(y) ) right++;
        if(y>0&&y>=abs(x)) down++;
        if(y<0&&abs(y)>=abs(x))up++;
    }
    
    if(left==0||right==0 ||up==0||down==0){
        ans=true;
    }
    if(ans){
        cout<<"YES"<<"\n";
    }else{
        cout<<"NO"<<"\n";
    }
    return 0;
}
