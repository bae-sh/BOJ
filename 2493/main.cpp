#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

int ans[500001];
stack<int> vec;
stack<pair<int,int>> st;//num , value
int n;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        vec.push(x);
    }
    while(!vec.empty()){
        int count = (int)vec.size();
        int cur =vec.top(); vec.pop();
        while(!st.empty()){
            pair<int,int> send=st.top();
            if(send.second<=cur){
                ans[send.first]=count;
                st.pop();
            }else{
                break;
            }
        }
        st.push({count,cur});
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
