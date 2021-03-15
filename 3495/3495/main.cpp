#include <iostream>
using namespace std;
int h,w,ans;
bool check;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>h>>w;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            char c; cin>>c;
            if(c== '.'){
                if(check){
                    ans++;
                }
            }else{
                if(check){
                    check=false;
                    ans++;
                }else{
                    check=true;
                }
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}
