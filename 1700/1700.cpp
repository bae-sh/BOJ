#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;

int N,K;
bool tapOn[101];
set<int> nextIdx[101];
vector<int> order;
int cnt;
int ans;

void selectIdx(){
 int maxOrder = 0;
 int idx = 0;
 ans++;

 for(int i=1;i<=K;i++){
 if(tapOn[i]){
 if(nextIdx[i].empty()){
 tapOn[i]=false;
 return;
 }

 int curOrder = *nextIdx[i].begin();
 if(maxOrder<curOrder){
 maxOrder=curOrder;
 idx=i;
 }
 }
 }

 nextIdx[idx].erase(maxOrder);
 tapOn[idx]=false;
}

int main(){
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 
 cin>>N>>K;
 cnt = N;
 for(int i=0;i<K;i++){
 int x; cin>>x;
 order.push_back(x);
 nextIdx[x].insert(i);
 }

 for(int i=0;i<order.size();i++){
 int cur = order[i];
 if(!tapOn[cur]){
 if(cnt!=0){
 cnt--;
 }else{
 selectIdx();
 
 }
 tapOn[cur]=true;
 nextIdx[cur].erase(i);
 }
 }
 cout<<ans<<"\n";
}

