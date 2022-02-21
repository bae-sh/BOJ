#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<cmath>
#define MAX 4000000
using namespace std;

bool primeNum[MAX+1];
vector<int> prime;
deque<int> dq;
int total;
int ans;
int N;
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin>>N;
    for(int i=2;i<=MAX;i++){
        primeNum[i]=true;
    }

    for(int i=2;i*i<=MAX;i++){
        if(!primeNum[i]) continue;
        for(int j=i*i;j<=MAX;j+=i){
            primeNum[j]=false;
        }
    }
    for(int i=2;i<=MAX;i++){
        if(primeNum[i]){
            prime.push_back(i);
        }
    }

    for(int i=0;i<prime.size();i++){
        int num = prime[i];
        total+=num;
        dq.push_back(num);
        if(total==N){
            ans++;
        }else{
            while(total>N && !dq.empty()){
                int temp = dq.front(); dq.pop_front();
                total-=temp;
                if(total==N){
                    ans++;
                }
            }
        }
    }
    cout<<ans<<'\n';
}
