#include<iostream>
#include<vector>
#include<queue>
#define INF 987654321
using namespace std;
int N;
int Dist[20][3];//weight1,weight2,w1*w2
int weight2[20][20];
vector<pair<int,int>> weight1[20];
priority_queue<pair<int,pair<int,pair<int, int>>>> pq;//cost pos,w1,w2
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char c; cin >> c;
			if (c == '.')continue;
			else {
				weight1[i].push_back({ j,c - '0' });
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char c; cin >> c;
			if (c == '.') continue;
			else {
				weight2[i][j] = c - '0';
			}
		}
	}
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			Dist[i][j] = INF;
		}
	}

	pq.push({ 0,{0,{0,0}} });
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second.first;
		int tw1 = pq.top().second.second.first;
		int tw2 = pq.top().second.second.second; pq.pop();

		for (int i = 0; i < weight1[cur].size(); i++) {
			int next = weight1[cur][i].first;
			int w1 = weight1[cur][i].second;
			if (weight2[cur][next] == 0) continue;
			int w2 = weight2[cur][next];
			if (Dist[next][2] > (w1 + Dist[cur][0]) * (w2 + Dist[cur][1])) {
				Dist[next][0] = w1 + Dist[cur][0];
				Dist[next][1] = w2 + Dist[cur][1];
				Dist[next][2] = Dist[next][0] * Dist[next][1];
				pq.push({ -Dist[next][2],{next,{Dist[next][0],Dist[next][1]}} });
			}
			else if (Dist[next][0] > tw1 + w1 || Dist[next][1] > tw2 + w2) {
				int nextw1 = tw1 + w1;
				int nextw2 = tw2 + w2;
				if (Dist[next][2] > nextw1 * nextw2) {
					Dist[next][0] = nextw1;
					Dist[next][1] = nextw2;
					Dist[next][2] = nextw1 * nextw2;
				}
				pq.push({ -(nextw1 * nextw2),{next,{nextw1,nextw2}} });
			}
		}
	}
	if (Dist[1][2] == INF) {
		cout << -1;
	}
	else {
		cout << Dist[1][2];
	}

}