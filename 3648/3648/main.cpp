#include <iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int> v[2001];
vector<int> rev[2001];
int scc[2001];
bool check[2001];
stack<int> st;
int n,m,idx;

void dfs(int x){
    check[x]=true;
    for(int i:v[x]){
        if(!check[i]){
            dfs(i);
        }
    }
    st.push(x);
}

void go(int x){
    scc[x]=idx;
    for(int i:rev[x]){
        if(scc[i]==0){
            go(i);
        }
    }
}
int f(int x){
    return (x<=n)? x+n:x-n;
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cout.tie(0); cin.tie(0);
    while(cin>>n>>m){
        idx=0;
        for(int i=0;i<2001;i++){
            v[i].clear();
            rev[i].clear();
            scc[i]=0;
            check[i]=false;
        }
        int a,b;
        for(int i=0;i<m;i++){
            cin>>a>>b;
            if(a<0) a=-a+n;
            if(b<0) b=-b+n;
            v[f(a)].push_back(b);
            rev[b].push_back(f(a));
            v[f(b)].push_back(a);
            rev[a].push_back(f(b));
        }
        a=1; b=1;
        v[f(a)].push_back(b);
        rev[b].push_back(f(a));
        v[f(b)].push_back(a);
        rev[a].push_back(f(b));
        for(int i=1;i<=n*2;i++){
            if(!check[i]){
            dfs(i);
            }
        }
        while(!st.empty()){
            int cur=st.top(); st.pop();
            if(!scc[cur]){
                ++idx;
                go(cur);
            }
        }
        bool t=true;
        for(int i=1;i<=n;i++){
            if(scc[i]==scc[i+n]){
                t=false;
                break;
            }
        }
        if(t){
            cout<<"yes\n";
        }else{
            cout<<"no\n";
        }
    }
    return 0;
}
