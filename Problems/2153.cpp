#include<iostream>
#include<string>
using namespace std;
int num[1500];//0이면 소수, 1이면 x
string words;
int ans;
int main() {
	num[1] = 0;
	for (int i = 2; i < 40; i++) {
		for (int j = i * i; j < 1500; j += i) {
			num[j] = 1;
		}
	}
	cin >> words;
	for (int i = 0; i < words.length(); i++) {
		if ('A' <= words[i]&& words[i] <= 'Z') {
			ans += words[i] - 'A' + 27;
		}
		else {
			ans += words[i] - 'a' + 1;
		}
	}
	if (num[ans]) {
		cout << "It is not a prime word.";
	}
	else {
		cout << "It is a prime word.";
	}
}