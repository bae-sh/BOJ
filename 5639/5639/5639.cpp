#include<iostream>
using namespace std;

struct Node {
	int value;
	Node* left;
	Node* right;
};

void postOrder(Node* n) {
	if (n == NULL) return;
	postOrder(n->left);
	postOrder(n->right);
	cout << n->value << "\n";
}

void insert(Node* &n, int num) {
	if (n == NULL) {
		n = new Node();
		n->value = num;
	}
	else if (n->value > num) {
		insert(n->left, num);
	}
	else {
		insert(n->right, num);
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	Node* root=new Node();
	int num;
	cin >> root->value;
	while (cin >> num) {
		insert(root, num);
	}
	postOrder(root);
}