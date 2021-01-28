#include <iostream>
#include <vector>
#define Mod 1000000007
using namespace std;
int D;
vector<int> v[8];
long long dp[8][100001];
void connect(){
    v[0].push_back(1);
    v[0].push_back(2);
    v[1].push_back(0);
    v[1].push_back(2);
    v[1].push_back(3);
    v[2].push_back(0);
    v[2].push_back(1);
    v[2].push_back(3);
    v[2].push_back(4);
    v[3].push_back(1);
    v[3].push_back(2);
    v[3].push_back(4);
    v[3].push_back(5);
    v[4].push_back(2);
    v[4].push_back(3);
    v[4].push_back(5);
    v[4].push_back(7);
    v[5].push_back(3);
    v[5].push_back(4);
    v[5].push_back(6);
    v[6].push_back(5);
    v[6].push_back(7);
    v[7].push_back(4);
    v[7].push_back(6);
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin>>D;
    connect();
    dp[0][0]=1;
    for(int i=1;i<=D;i++){
        for(int j=0;j<8;j++){
            for(int k=0;k<v[j].size();k++){
                int pre= v[j][k];
                dp[j][i]+=dp[pre][i-1];
                dp[j][i]%=Mod;
            }
        }
    }
    cout<<dp[0][D]<<"\n";
    return 0;
}
