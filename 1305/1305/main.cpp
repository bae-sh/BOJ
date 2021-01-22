#include <iostream>
#include<vector>
#include<string>
using namespace std;
int L;
string orgin;
vector<int> pi(L,0);
void getPi(string s){
    int m=s.size(); int j=0;
    for(int i=1;i<s.size();i++){
        while(j>0&&s[i]!=s[j]){
            j=pi[j-1];
        }
        if(s[i]==s[j]){
            pi[i]=++j;
        }
    }
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin>>L>>orgin;
    getPi(orgin);
    cout<<L-pi[L-1]<<"\n";
    return 0;
}
