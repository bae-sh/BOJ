#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n,x,y;
int line_x[1000001];
int line_y[1000001];
vector<pair<int,int>> point;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        point.push_back({x+500000,y+500000});
    }
    point.push_back({point[0].first,point[0].second});
    
    for(int i=0;i<point.size()-1;i++){
        int x1=point[i].first; int y1=point[i].second;
        int x2=point[i+1].first; int y2=point[i+1].second;
        if(x1==x2){//세로
            line_y[min(y1,y2)]++;
            line_y[max(y1,y2)]--;
        }else{
            line_x[min(x1,x2)]++;
            line_x[max(x1,x2)]--;
        }
    }
    int x_max = line_x[0];
    int y_max = line_y[0];
    for(int i=1;i<1000001;i++){
        line_x[i]+=line_x[i-1];
        line_y[i]+=line_y[i-1];
        x_max = max(line_x[i],x_max);
        y_max = max(line_y[i],y_max);
    }
    cout<<max(x_max, y_max)<<"\n";
    return 0;
}
