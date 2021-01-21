#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<int,int>> v;
vector<int> ans;
int sum;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    for(int i=0;i<8;i++){
        int n; cin>>n;
        v.push_back({n,i+1});
    }
    sort(v.begin(),v.end());
    for(int i=7;i>=3;i--){
        sum+=v[i].first;
        ans.push_back(v[i].second);
    }
    sort(ans.begin(),ans.end());
    cout<<sum<<"\n";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}
