#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
int N, before;
stack<int> ans;
stack<int> st;
int RBig[1000001];
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin>>N;
    for(int i=0;i<N;i++){
        int x; cin>>x;
        st.push(x);
    }
    while(!st.empty()){
        int cur = st.top(); st.pop();
        if(before==0){
            ans.push(-1);
            RBig[cur] = -1;
        }else{
            int next = before;
            while(true){
                if(next>cur || next == -1) break;
                next = RBig[next];
            }
            ans.push(next); RBig[cur] = next;
        }
        before = cur;
    }
    while(!ans.empty()){
        cout<< ans.top() <<" "; ans.pop();
    }
    return 0;
}
