#include <iostream>
using namespace std;
int T;

int main(int argc, const char * argv[]) {
    cin>>T;
    while(T--){
        int ans=0;
        int x1,x2,y1,y2; cin>>x1>>y1>>x2>>y2;
        int n; cin>>n;
        for(int i=0;i<n;i++){
            int x,y,r; cin>>x>>y>>r;
            bool start = ((x1-x)*(x1-x)+(y1-y)*(y1-y))<r*r;
            bool end =((x2-x)*(x2-x)+(y2-y)*(y2-y))<r*r;
            if(start!=end){
                ans++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
