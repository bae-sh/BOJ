#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
using namespace std;

string Sa;
string Sb;
int ans;
set<vector<int>> s;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>Sa>>Sb;
    for(int i=0;i<Sa.size();i++){
        vector<int> v(26);
        for(int j=i;j<Sa.size();j++){
            int idx=Sa[j]-'a';
            v[idx]++;
            s.insert(v);
        }
    }
    
    for(int i=0;i<Sb.size();i++){
        vector<int> v(26);
        for(int j=i;j<Sb.size();j++){
            int idx=Sb[j]-'a';
            v[idx]++;
            if(s.count(v)){
                ans = max(ans,j-i+1);
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}
