#include <iostream>
#include <algorithm>
#include <vector>
using  namespace std;
int n;
int pre=-1;
bool up = true;
int cnt;
int ans;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        if(up){
            if(pre>x){
                up=false;
                cnt++;
            }
        }else{
            if(pre<x){
                up=true;
            }
        }
        pre=x;
    }
    if(cnt&&up) cnt++;
    if(cnt!=0){
        ans=1;
        while(cnt!=1){
            cnt=(cnt+1)/2;
            ans++;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
