#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

int N, M;
vector<int> v[10001];
bool visited[10001];
int ans[10001];
int maxValue = -1;

int dfs(int node)
{
    visited[node] = true;
    int count = 1;
    for (auto cur : v[node])
    {
        if(!visited[cur]){
            count+=dfs(cur);
        }
    }
    return count;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;

    for (int i = 0; i < M;i++){
        int A, B;
        cin >> A >> B;
        v[B].push_back(A);
    }
    for (int i = 1; i <= N;i++){
        memset(visited, false, sizeof(visited));
        ans[i] = dfs(i);
        maxValue = max(maxValue, ans[i]);
    }
    for (int i = 1; i <= N;i++){
        if(maxValue==ans[i]){
            cout << i << " ";
        }
    }
}