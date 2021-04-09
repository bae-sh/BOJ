#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#define mod 1000000007
using namespace std;
typedef vector<vector<long long>> matrix;

matrix operator * (matrix& a, matrix& b)
{
    matrix c(2, vector<long long>(2));

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++){
            for (int k = 0; k < 2; k++)
                c[i][j] += a[i][k] * b[k][j];

            c[i][j] %= mod;
        }
    return c;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    long long n; cin>>n;
    matrix ans = {{1,0}, {0,1}};
    matrix a[65];
    a[0]={{1,1}, {1,0}};
    for(int i=1;i<65;i++){
        a[i]=a[i-1]*a[i-1];
    }
    int i=63;
    while(n>0){
        long long num=(long long)pow(2, i);
        if(num<=n){
            ans = ans*a[i];
            n-=num;
        }
        i--;
    }
    cout<<ans[0][1]<<"\n";
    return 0;
}
