#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
#define INF 987654321;

int N, M;
int ans = INF;
int map[50][50];
vector<pair<int, int>> home;
vector<pair<int, int>> chicken;
bool use_chicken[20];

void dfs(int chickenNum, int cnt) {//선택한 치킨집,제귀 들어온 횟수
	if (cnt > chicken.size()) return;
	if (chickenNum == M) {
		int dist = 0;
		for (int i = 0; i < home.size(); i++) {
			int cost = INF;
			for (int j = 0; j < chicken.size(); j++) {
				if (use_chicken[j]) {
					cost = min(cost, abs(home[i].first - chicken[j].first) + abs(home[i].second - chicken[j].second));
				}
			}
			dist += cost;
		}
		ans = min(ans, dist);
	}
	use_chicken[cnt] = 1;//백트레킹알고리즘
	dfs(chickenNum + 1, cnt + 1);
	use_chicken[cnt] = 0;
	dfs(chickenNum, cnt + 1);
}
int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1) home.push_back(make_pair(i, j));
			else if (map[i][j] == 2) chicken.push_back(make_pair(i, j));
		}
	}
	dfs(0, 0);
	printf("%d", ans);
}