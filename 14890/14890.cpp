#include<iostream>
#include<algorithm>
using namespace std;

int N,L;
int MAP1[100][100];
int MAP2[100][100];
bool putBridge(int A[][100],int x,int y){
    int count = 1;
    for(int i=y;i<N-1;i++){
        if(A[x][i]==A[x][i+1]){
            count++;
        }else{
            break;
        }
    }
    if(count>=L){
        return true;
    }else{
        return false;
    }
}

int getRoad(int A[][100]){
    int count =0;
    for(int i=0;i<N;i++){
        int len = 1;
        bool canPut = true;

        for(int j=0;j<N-1;j++){
            if(A[i][j]==A[i][j+1]){
                len++;
            }else if(A[i][j]==A[i][j+1]-1){
                if(len>=L){
                    len=1;
                }else{
                    canPut=false;
                    break;
                }
            }else if(A[i][j]==A[i][j+1]+1){
                if(putBridge(A,i,j+1)){
                    j=j+L-1;
                    len =0;
                }else{
                    canPut=false;
                    break;
                }
            }else{
                canPut=false;
                break;
            }
        }
        if(canPut){
            count++;
        }
    }
    return count;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>N>>L;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>MAP1[i][j];
            MAP2[j][i]=MAP1[i][j];
        }
    }
    cout<<getRoad(MAP1)+getRoad(MAP2)<<"\n";
}