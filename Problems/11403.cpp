#include<stdio.h>
#include<vector>
using namespace std;
int N, value;
int Graph[100][100];
vector<int>v[100];//<next>[start]
void connect(int start, int next) {
	if (Graph[start][next] == 1) return;
	Graph[start][next] = 1;
	for (int i = 0; i < v[next].size(); i++) {
		connect(start, v[next][i]);
	}
	return;
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &value);
			if (value) {
				v[i].push_back(j);
			}
			Graph[i][j] = 0;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < v[i].size(); j++) {
			connect(i, v[i][j]);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", Graph[i][j]);
		}
		printf("\n");
	}
}