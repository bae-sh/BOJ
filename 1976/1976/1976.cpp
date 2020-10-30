#include<iostream>
#include<algorithm>
using namespace std;
int N, M;
int way[201][201];
bool p;
int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> way[i][j];
		}
	}
	for (int k = 1; k <= N; k++) {//stop by k
		for (int i = 1; i <= N; i++) {//begin
			for (int j = 1; j <= N; j++) {//end
				if (way[i][k] != 0 && way[k][j] != 0||(i==j)) {
					way[i][j] = 1;
				}
			}
		}
	}
	p = true;
	int start; cin >> start;
	for (int i = 1; i < M; i++) {
		int next; cin >> next;
		if (!way[start][next]) {
			p = false;
			break;
		}
	}
	if (p) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}

}
