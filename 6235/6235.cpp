#include<iostream>
#include<algorithm>
#include<queue>
#include<string>
using namespace std;

priority_queue<pair<pair<int, int>,int>> pq;
int cnt;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while(true){
        string s;
        cin >> s;
        if(s=="#")
            break;
        int x, y;
        cin >> x >> y;
        pq.push({{-y, -x},-y});
    }
    cin >> cnt;
    while (cnt--)
    {
        auto t = pq.top();
        pq.pop();
        cout << -t.first.second << "\n";
        pq.push({{t.first.first + t.second, t.first.second}, t.second});
    }
}