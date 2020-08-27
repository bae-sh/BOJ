#include<stdio.h>
#include<cmath>
#include<algorithm>
using namespace std;
int X[3];
int Y[3];
double dis[3];
double Max;
double Min = 1000000000;
int main() {
	for (int i = 0; i < 3; i++) {
		scanf("%d %d", &X[i], &Y[i]);
	}
	for (int i = 0; i < 3; i++) {
		dis[i] = sqrt((X[i] - X[(i + 1) % 3])*(X[i] - X[(i + 1) % 3])+ (Y[i] - Y[(i + 1) % 3])*(Y[i] - Y[(i + 1) % 3]));
	}
	if ((Y[0]-Y[1])*(X[1]-X[2])== (Y[1] - Y[2])*(X[0] - X[1])) {
		printf("-1");
	}
	else {
		for (int i = 0; i < 3; i++) {
			double distance = (dis[i] + dis[(i + 1) % 3]) * 2;
			Max = max(Max, distance);
			Min = min(Min, distance);
		}
		printf("%.16lf", Max - Min);
	}
}