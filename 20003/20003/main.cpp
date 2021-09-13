#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;
int n;
vector<pair<long long,long long>> v;
long long gcd(long long a, long long b){
    long long n;
    swap(a,b);
    while(b!=0){
        n = a%b;
        a = b;
        b = n;
    }
    return a;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        long long x,y; cin>>x>>y;
        v.push_back({x,y});
    }
    long long b=v[0].second;
    
    for(int i=1;i<n;i++){
        long long y=v[i].second;
        b=b*y/gcd(b,y);
    }
    long long a=v[0].first*(b/v[0].second);
    
    for(int i=1;i<n;i++){
        long long y=v[i].first*(b/v[i].second);
        a=gcd(a,y);
    }
    long long g=gcd(a,b);
    
    cout<<a/g<<" "<<b/g;
    return 0;
}
