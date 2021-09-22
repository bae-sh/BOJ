#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N,M;
bool dp[40001];
vector<int> v;
int main(int argc, const char * argv[]) {
    cin>>N;
    for(int i=0;i<N;i++){
        int x; cin>>x;
        v.push_back(x);
    }
    dp[0]=true;
    
    for(int i=0;i<N;i++){
        int cur =v[i];
        vector<int> ans;
        for(int j=40000;j>=0;j--){
            if(dp[j]&& cur-j>=0){
                ans.push_back(cur-j);
            }
            if(dp[j]&& j-cur>=0){
                ans.push_back(j-cur);
            }
            if(j-cur>=0 && dp[j-cur]){
                ans.push_back(j);
            }
        }
        for(int j=0;j<ans.size();j++){
            dp[ans[j]]=true;
        }
    }
    cin>>M;
    
    for(int i=0;i<M;i++){
        int x; cin>>x;
        if(dp[x]){
            cout<<"Y ";
        }else{
            cout<<"N ";
        }
    }
    return 0;
}
