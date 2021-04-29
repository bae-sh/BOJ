#include <iostream>
using namespace std;
int M,N;
int grow[1400]={1};
int map[700][700];
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>M>>N;
    for(int i=0;i<N;i++){
        int a,b,c; cin>>a>>b>>c;
        grow[a]++; grow[a+b]++;
    }
    for(int i=1;i<2*M-1;i++){
        grow[i]+=grow[i-1];
    }
    for(int i=0;i<M-1;i++){
        map[M-i-1][0]=grow[i];
    }
    for(int i=M-1;i<2*M-1;i++){
        map[0][i-M+1]=grow[i];
    }
    for(int i=0;i<M;i++){
        cout<<map[0][i]<<" ";
    }
    cout<<"\n";
    for(int i=1;i<M;i++){
        cout<<map[i][0]<<" ";
        for(int j=1;j<M;j++){
            cout<<map[0][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
