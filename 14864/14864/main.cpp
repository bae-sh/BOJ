#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N,M,X,Y;
int order[100001];
bool check[100001];

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        order[i]=i;
    }
    for(int i=0;i<M;i++){
        cin>>X>>Y;
        order[X]++; order[Y]--;
    }
    for(int i=1;i<=N;i++){
        if(order[i]>N || order[i]<1|| check[order[i]]){
            cout<<-1<<"\n";
            return 0;
        }
        check[order[i]]=true;
    }
    for(int i=1;i<=N;i++){
        cout<<order[i]<<" ";
    }
    return 0;
}
