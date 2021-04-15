#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
int cur_parent[200001];
int parent[200001];
stack<vector<int>> order;
stack<int> ans;
int find_parent(int x){
    if(cur_parent[x] == x) return x;
    return cur_parent[x] = find_parent(cur_parent[x]);
}
void Union(int x,int y){
    x = find_parent(x);
    y = find_parent(y);
    cur_parent[x] = y;
}

int N,Q;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin>>N>>Q;
    for(int i=1;i<N;i++){
        cur_parent[i] = parent[i] = i;
    }
    
    for(int i=1;i<N;i++){
        int x; cin>>x;
        parent[i+1] = x;
    }
    for(int i=0;i<N-1+Q;i++){
        int a,b,c; cin>>a>>b;
        vector<int> v;
        v.push_back(a);
        v.push_back(b);
        if(a==1){
            cin>>c;
            v.push_back(c);
        }
        order.push(v);
    }
    
    while(!order.empty()){
        vector<int> v = order.top(); order.pop();
        int a=v[0]; int cur = v[1];
        if(a==0){
            Union(cur, parent[cur]);
        }else{
            int next = v[2];
            cur=find_parent(cur);
            next=find_parent(next);
            if(cur==next){
                ans.push(1);
            }else{
                ans.push(0);
            }
        }
    }
    while(!ans.empty()){
        if(ans.top()==1){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
        ans.pop();
    }
}
