#include<stdio.h>
#include<algorithm>

using namespace std;
int N, M;
int a[15000];
int check[15000];
int ans;

int main() {
	scanf("%d", &N);
	scanf("%d", &M);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + N);

	for (int i = 0; i < N - 1; i++) {
		if (check[i] != 0) {
			continue;
		}else{
			for (int j = i + 1; j < N; j++) {
				if (check[j] != 0) {
					continue;
				}
				else {
					if (a[i] + a[j] == M) {
						ans++;
						check[i] = check[j] = 1;
						break;
					}
				}
			}
		}
		
	}
	printf("%d", ans);

}