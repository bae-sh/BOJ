#include <iostream>
#include <string>
using namespace std;
string s;
bool ans=true;
int status; //0: 기본, 1: 100, 2: 100~1,
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(status==0){
            if(s[i]=='0'){
                if(i+1<s.length()&&s[i+1]=='1'){
                    i++;
                }else{
                    ans=false;
                }
            }else{
                if(i+2<s.length()&&s[i+1]=='0'&&s[i+2]=='0'){
                    i+=2;
                    status=1;
                }else{
                    ans=false;
                }
            }
        }else if(status==1){
            if(s[i]=='0') continue;
            if(s[i]=='1'){
                status=2;
            }
        }else if(status==2){
            if(s[i]=='0'){
                if(i+1<s.length()&&s[i+1]=='1'){
                    i++;
                    status=0;
                }else{
                    ans=false;
                }
            }else if(s[i]=='1'){
                if(i+2<s.length()&&s[i+1]=='0'&&s[i+2]=='0'){
                    i+=2;
                    status=1;
                }
            }
        }
    }
    if(!ans||status==1){
        cout<<"NOISE\n";
    }else{
        cout<<"SUBMARINE\n";
    }
    return 0;
}
