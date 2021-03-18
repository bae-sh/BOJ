#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
string S,T;
int ans = 1;
int cur_index = -1;
vector<int> alpa[26];

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin>>S>>T;
    for(int i=0;i<T.length();i++){
        int index=T[i]-'a';
        alpa[index].push_back(i);
    }
    for(int i=0;i<S.length();i++){
        int index=S[i]-'a';
        int temp = upper_bound(alpa[index].begin(), alpa[index].end(), cur_index)-alpa[index].begin();
        if(temp==alpa[index].size()){
            if(cur_index==-1){
                ans = -1;
                break;
            }else{
                ans++;
                i--;
                cur_index=-1;
                continue;
            }
        }
        cur_index = alpa[index][temp];
    }
    cout<<ans<<"\n";
    return 0;
}
