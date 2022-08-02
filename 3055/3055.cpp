#include<iostream>
#include<algorithm>
#include<queue>
#include<string>
using namespace std;

int R, C;
int water[51][51];
bool visited[51][51];
int sx, sy;

int dx[] = {-1, 0, 1, 0};
int dy[] = { 0, 1, 0, -1 };

int ans = -1;

queue<pair<pair<int,int>,int>> waterq;
void fillWater() {
    while (!waterq.empty()) {
        int x = waterq.front().first.first;
        int y = waterq.front().first.second;
        int z = waterq.front().second;
        waterq.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < R && 0 <= ny && ny < C) {
                if (water[nx][ny] == -1) {
                    water[nx][ny] = z + 1;
                    waterq.push({{nx, ny}, z + 1});
                }
            }
        }
    }
}
void bfs(int x, int y,int depth) {
    queue<pair<pair<int,int>,int>> q;
    q.push({{x, y}, depth});
    while (!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int z = q.front().second;
        q.pop();
        visited[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < R && 0 <= ny && ny < C) {
                if (!visited[nx][ny]) {
                    if (water[nx][ny] == -3) {
                        ans = z + 1;
                        return;
                    } else if (water[nx][ny] == -2) {
                        continue;
                    } else if (water[nx][ny] > z + 1 || water[nx][ny]==-1) {
                        q.push({{nx, ny}, z + 1});
                    }
                }
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> R >> C;
    for (int i = 0; i < R;i++){
            for (int j = 0; j < C;j++){
                water[i][j] = -1;
            }
        }
    for (int i = 0; i < R;i++){
        string s;
        cin >> s;
        
        for (int j = 0; j < C; j++)
        {
            if(s[j]=='S'){
                sx = i;
                sy = j;
            }else if(s[j]=='*'){
                waterq.push({{i, j}, 0});
                water[i][j] = 0;
            }else if(s[j]=='X'){
                water[i][j] = -2;
            }else if(s[j]=='D'){
                water[i][j] = -3;
            }
        }
    }
    
    fillWater();
    bfs(sx, sy, 0);
    if(ans==-1){
        cout << "KAKTUS\n";
    }else{
        cout << ans << "\n";
    }
}