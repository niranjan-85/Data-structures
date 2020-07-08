#include <bits/stdc++.h>
using namespace std;

typedef struct node {
	int data;
	node* left, *right;
};

node* newnode;

void preorder(node* p) {
	if (p) {
		preorder(p->left);
		cout << p->data<<" ";
		preorder(p->right);
	}
}


node * create(int key,node *temp) {
	if (temp == NULL) {
		newnode = new node;
		newnode->left = newnode->right = NULL;
		newnode->data = key;
		return newnode;
	}
	else if (key > temp->data) {
		temp->right = create(key, temp->right);
	}
	else {
		temp->left=create(key,temp->left);
	}
	return temp;

}

void main() {
	int a[100], n;
	cout << "Enter the elemets of a BST" << endl;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	node* root = NULL;
	root = create(a[0],root);
	for (int i = 1; i < n; i++) {
		create(a[i], root);
	}
	preorder(root);
	
}