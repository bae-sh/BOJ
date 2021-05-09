#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int N, C, M;
int box[2001];
int ans;
struct Box {
	int start, end, cnt;
	bool operator < (Box b) {
		if (end != b.end) {
			return end < b.end;
		}
		else {
			return start < b.start;
		}
	}
};

vector <Box> v;
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N >> C >> M;
	for (int i = 0; i < M; i++) {
		Box b; cin >> b.start >> b.end >> b.cnt;
		v.push_back(b);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < M; i++) {
		Box b = v[i];
		int putBox = b.cnt;
		for (int j = b.start; j < b.end; j++) {
			if (box[j] + putBox > C) {
				putBox = C - box[j];
			}
		}
		for (int j = b.start; j < b.end; j++) {
			box[j] += putBox;
		}
		ans += putBox;
	}
	cout << ans << "\n";
}