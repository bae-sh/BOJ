#include<iostream>
#include<algorithm>
#include<vector>
#define MAX 2100000000
using namespace std;

int N;
int leftIdx,rightIdx;
vector<int> v;
int ans=MAX;
int a1,a2;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>N;
    for(int i=0;i<N;i++){
        int x; cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());

    rightIdx=N-1;
    while(leftIdx<rightIdx){
        int temp = v[leftIdx]+v[rightIdx];
        if(abs(temp)<abs(ans)){
            a1=v[leftIdx];
            a2=v[rightIdx];
            ans=temp;
        }
        if(temp>0){
            rightIdx--;
        }else{
            leftIdx++;
        }
    }
    cout<<a1<<" "<<a2<<"\n";
}
