#include <iostream>
#include <vector>
#define MIN -2100000000
using namespace std;
vector<int> v;
int ans[50];

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N; cin>>N;
    for(int i=0;i<N;i++){
        int a; cin>>a;
        v.push_back(a);
    }
    for(int i=0;i<N;i++){
        double tilt = MIN;
        for(int j=i;j<N;j++){
            double new_tilt = (v[j]-v[i])*1.0/(j-i);
            if(tilt<new_tilt){
                ans[i]++; ans[j]++;
                tilt=new_tilt;
            }
        }
    }
    for(int i=0;i<N;i++){
        if(ans[0]<ans[i]){
            ans[0]=ans[i];
        }
    }
    cout<<ans[0]<<"\n";
    return 0;
}
