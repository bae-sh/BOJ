#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
int T;
vector<int> go(string s,int len){
    vector<int> v(len+1);
    
    int t=0;
    for(int i=0;i<s.size();i++){
        if(i+1<s.size() && s[i]=='(' && s[i+1]==')'){
            v[t]++;
            i++;
        }else if(s[i]=='('){
            t++;
        }else{
            t--;
        }
       
    }
    for(int i=0;i<len;i++){
        v[i+1]+=v[i]/2;
        v[i]%=2;
    }
    reverse(v.begin(), v.end());
    return v;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>T;
    while(T-->0){
        string A,B; cin>>A>>B;
        int len = (int)max(A.size(),B.size());
        auto ansA=go(A,len);
        auto ansB=go(B,len);
        if(ansA>ansB){
            cout<<">\n";
        }else if(ansA==ansB){
            cout<<"=\n";
        }else{
            cout<<"<\n";
        }
    }
    return 0;
}
