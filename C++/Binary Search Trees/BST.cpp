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

void create(int a[],int n,node * root) {
	for (int i = 1; i < n; i++) {
		node* temp = root;
		node* tail = NULL;
		while (temp != NULL) {
			tail = temp;
			if (a[i] > temp->data) {
				temp = temp->right;
			}
			else if (a[i] < temp->data) {
				temp = temp->left;
			}
		}
		newnode = new node;
		newnode->left = newnode->right = NULL;
		newnode->data = a[i];
		tail->data < newnode->data ? tail->right = newnode : tail->left = newnode;

	}
	preorder(root);
	
}

void main() {
	int a[100], n;
	cout << "Enter the elemets of a BST" << endl;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	newnode = new node;
	newnode->left = newnode->right = NULL;
	newnode->data = a[0];
	create(a,n,newnode);
}