#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
string dp[1001][2];
void copyDp(){
    for(int i=0;i<1001;i++){
        dp[i][0]=dp[i][1];
    }
}
int main(){
    string s1,s2; cin>>s1>>s2;
    for(int i=0;i<s1.length();i++){
        char a = s1[i];
        for(int j=0;j<s2.length();j++){
            char b = s2[j];
            dp[j+1][1] = dp[j+1][0].length()>dp[j][1].length() ? dp[j+1][0] : dp[j][1];
            if(a==b){
                dp[j+1][1] = dp[j+1][1].length() > dp[j][0].length()+1 ? dp[j+1][1] : dp[j][0]+a;
            }
        }
        copyDp();
    }
    cout<<dp[s2.length()][1].length()<<"\n"<<dp[s2.length()][1]<<"\n";
}
