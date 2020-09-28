#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
int N;
int score[300000];
int ans;
int need;
bool desc(int a, int b) {
	return a > b;
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &score[i]);
	}
	sort(score, score + N,desc);
	for (int i = 0; i < N ; i++) {
		ans += (score[i] + N >= need);
		need = max(need, score[i] + i + 1);
	}
	printf("%d", ans);
}