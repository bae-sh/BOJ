#include<stdio.h>
using namespace std;
int T;
int main() {
	scanf("%d", &T);
	while (T-- > 0) {
		int n = 0;
		scanf("%d", &n);
		int C = 0;
		double G = 0;
		for (int i = 0; i < n; i++) {
			int c = 0;
			double g = 0;
			scanf("%d %lf", &c, &g);
			C += c;
			G += g * c;
		}
		G = G / C;;
		printf("%d %.1lf\n", C, G);
	}
}