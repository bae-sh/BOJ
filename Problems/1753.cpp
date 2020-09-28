#include<stdio.h>
#include<queue>
#define INF 987654321
using namespace std;

int V, E, K;
vector<pair<int, int>> v[20001];
priority_queue<pair<int, int>> PQ;//현재 가지고 있는 가중치,다음 노드
int Dist[20001];
int main() {
	scanf("%d %d\n%d", &V, &E, &K);
	for (int i = 1; i <= V; i++) {
		Dist[i] = INF;
	}
	for (int i = 0; i < E; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		v[a].push_back(make_pair(b, c));
	}

	Dist[K] = 0;
	PQ.push(make_pair(0, K));
	while (!PQ.empty()) {
		int cCost = -PQ.top().first;
		int Cur = PQ.top().second;
		PQ.pop();
		for (int i = 0; i < v[Cur].size(); i++) {
			int Next = v[Cur][i].first;
			int nCost = v[Cur][i].second;
			if (Dist[Next] > cCost + nCost) {
				Dist[Next] = cCost + nCost;
				PQ.push(make_pair(-Dist[Next], Next));
			}
		}
	}
	for (int i = 1; i <= V; i++) {
		if (Dist[i] == INF) {
			printf("INF\n");
		}
		else {
			printf("%d\n", Dist[i]);
		}
	}
}