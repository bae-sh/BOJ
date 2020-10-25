#include<stdio.h>
#include<vector>
#include<queue>
#define INF 987654321
using namespace std;
int n, m;
vector <pair<int, int>> v[101];//도착도시,비용
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		v[a].push_back(make_pair(b, c));
	}
	for (int i = 1; i <= n; i++) {
		int Dist[101];
		for (int j = 0; j < 101; j++) {
			Dist[j] = INF;
		}
		Dist[i] = 0;
		priority_queue<pair<int, int>> pq;//가중치,다음값
		pq.push(make_pair(0, i));
		while (!pq.empty()) {
			int cCost = -pq.top().first;
			int Cur = pq.top().second;
			pq.pop();
			for (int j = 0; j < v[Cur].size(); j++) {
				int nCost = v[Cur][j].second;
				int next = v[Cur][j].first;
				if (Dist[next] > cCost + nCost) {
					Dist[next] = cCost + nCost;
					pq.push(make_pair(-Dist[next], next));
				}
			}
		}
		for (int j = 1; j <= n; j++) {
			if (Dist[j] == INF) {
				Dist[j] = 0;
			}
			printf("%d ", Dist[j]);
		}
		printf("\n");
	}
}