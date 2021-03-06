#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
vector<pair<pair<int,int>,pair<int,int>>> v;
vector<int> connect[3000];
bool check[3000];
int N,cnt;
int group_cnt;
int group_max;
int CCW(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3)
{
    int op = (p2.first-p1.first)*(p3.second-p1.second)-(p2.second-p1.second)*(p3.first-p1.first);

    if (op > 0) return 1;
    else if (op == 0) return 0;
    else return -1;
}

bool CheckIntersect(int line1, int line2)
{
    pair<int, int> p1 = v[line1].first;
    pair<int, int> p2 = v[line1].second;
    pair<int, int> p3 = v[line2].first;
    pair<int, int> p4 = v[line2].second;

    int line1_2 = CCW(p1, p2, p3) * CCW(p1, p2, p4);
    int line2_1 = CCW(p3, p4, p1) * CCW(p3, p4, p2);

    if (line1_2 == 0 && line2_1 == 0)
    {
        if (p1 > p2) swap(p1, p2);
        if (p3 > p4) swap(p3, p4);

        return p1 <= p4 && p3 <= p2;
    }
    return line1_2 <= 0 && line2_1 <= 0;
}

void dfs(int num){
    cnt++;
    check[num]=true;
    for(int i:connect[num]){
        if(!check[i]){
            dfs(i);
        }
    }
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N; cin>>N;
    for(int i=0;i<N;i++){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        v.push_back({{x1,y1},{x2,y2}});
    }
    for(int i=0;i<N;i++){
        for(int j=1;j<N;j++){
            if(CheckIntersect(i, j)){
                connect[i].push_back(j);
                connect[j].push_back(i);
            }
        }
    }
    for(int i=0;i<N;i++){
        if(!check[i]){
            group_cnt++;
            cnt=0;
            dfs(i);
            group_max=max(group_max,cnt);
        }
    }
    cout<<group_cnt<<"\n"<<group_max<<"\n";
    return 0;
}
