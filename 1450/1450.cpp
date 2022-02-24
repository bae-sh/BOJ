#include<iostream>
#include<algorithm>
#include<string.h>
#include<map>
#include<vector>
using namespace std;

int N,C;
vector<int> w;
map<int,int> m[31];
int ans;

int main(){
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin>>N>>C;
    m[0][0]=1;

    for(int i=0;i<N;i++){
        int x; cin>>x;
        w.push_back(x);
    }

    for(int i=1;i<=N;i++){
        int weight = w[i-1];
        for(auto iter = m[i-1].begin();iter!=m[i-1].end();iter++){
            int key = iter->first; //weight
            int value = iter->second; // 누적합

            m[i][key]+=value;
            if(key+weight<=C){
                m[i][key+weight]+=m[i-1][key];
            }
        }
    }
    for(auto iter = m[N].begin();iter!=m[N].end();iter++){
        ans+=iter->second;
    }
    cout<<ans<<'\n';
}

