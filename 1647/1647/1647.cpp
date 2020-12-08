#include<iostream>
#include<vector>

using namespace std;
int N;
int parent[100001];

int Find(int x) {
	if (parent[x] == 0) {
		return 0;
	}
	else if (parent[x] == x) {
		return x;
	}
	else {
		return parent[x] = Find(x);
	}
}
void Union(int x, int y) {
	int parent_x = Find(x);
	int parent_y = Find(y);
	if (parent_x == 0) {

	}
}
int main() {

}