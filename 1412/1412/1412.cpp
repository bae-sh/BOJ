#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N;
vector<int> v[100];
vector<pair<int, int>> v2;//양방향
char map[100][100];
queue<pair<int,int>> q;//자신,부모
bool impossible;
int indegree[100];
int parent[100][100];//자신,부모,몇대손

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char c; cin >> c;
			map[i][j] = c;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 'Y') {
				if (map[j][i] == 'Y' && i <= j) {
					v2.push_back({ i,j });
				}
				else if (map[j][i] == 'N') {
					v[i].push_back(j);
					indegree[j]++;
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		if (indegree[i] == 0) {
			q.push({ i,i });
			parent[i][i] = 1;
		}
	}
	
	while (!q.empty()) {
		int cur = q.front().first; 
		int p = q.front().second; q.pop();
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i];
			if (parent[next][p] != 0) {
				cout << "NO";
				return 0;
			}
			else {
				parent[next][p] = parent[cur][p] + 1;
				q.push({ next,p });
			}
		}
	}
}