#include<stdio.h>
#include<algorithm>
using namespace std;
int a[3];

int main() {
	for (int i = 0; i < 3; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + 3);
	int first = a[1] - a[0];
	int second = a[2] - a[1];
	if (first == second) {
		printf("%d", a[2] + first);
	}
	else if(first>second){
		printf("%d", a[0] + second);
	}
	else {
		printf("%d", a[1] + first);
	}

}