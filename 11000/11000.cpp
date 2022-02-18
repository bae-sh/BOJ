#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
priority_queue<int> q;
vector<pair<int, int>> v;
int N;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >>N;
    for (int i = 0; i < N;i++){
        int start, end;
        cin >> start >> end;
        v.push_back({start, end});
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < v.size();i++){
        int start = v[i].first;
        int end = v[i].second;
        if (q.empty())
        {
            q.push(-end);
        }
        else
        {
            if(-q.top()<=start){
                q.pop();
            }
            q.push(-end);
        }
    }
    cout << q.size() << '\n';
}