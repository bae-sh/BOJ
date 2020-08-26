#include<iostream>
#include<algorithm>
using namespace std;
long long N;
int x[] = { -1,0,1,0 };
int y[] = { 0,1,0,-1 };
int Dice[6];
int a=1000000000,b= 1000000000,c= 1000000000;//1면,2면,3면최소
int Max;
long long ans;
int main() {
	cin >> N;
	for (int i = 0; i < 6; i++) {
		cin >> Dice[i];
		a = min(Dice[i], a);
		Max = max(Max, Dice[i]);
	}
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if ((i != j) && (i + j != 5)) {
				b = min(b, Dice[i] + Dice[j]);
			}
		}
	}
	int Dice_2[3][6] = { {Dice[3],Dice[3],Dice[3],Dice[3],Dice[3],Dice[3]},{Dice[5],Dice[4],Dice[0],Dice[1],Dice[5],Dice[4]},{Dice[2],Dice[2],Dice[2],Dice[2],Dice[2],Dice[2]} };
	for (int i = 1; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			c = min(c, Dice_2[1][i] + Dice_2[1 + x[j]][i + y[j]] + Dice_2[1 + x[(j + 1) % 4]][i + y[(j + 1) % 4]]);
		}
	}
	if (N == 1) {
		for (int i = 0; i < 6; i++) {
			ans += Dice[i];
		}
		ans -= Max;
	}
	else {
		ans += 5 * a*(N - 2)*(N - 2) + 4 * a*(N - 2);
		ans += 4 * b*(N - 1) + 4 * b*(N - 2);
		ans += 4 * c;
	}
	cout << ans;
}