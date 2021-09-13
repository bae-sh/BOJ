#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    int A; cin>>A;
    vector<int> ans;
    for(int i=1;i<=31;i++){
        int x=30;
        while(x>0){
            x-=(i+1);
        }
        if(x==0){
            ans.push_back(i);
        }
    }
    for(int i=0;i<ans.size();i++){
        if(ans[i]<=A){
            cout<<ans[i]<<"\n";
        }else{
            break;
        }
    }
    return 0;
}
