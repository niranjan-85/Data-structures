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


node* make(node *ptr,int k) {
	newnode = new node;
	newnode->left = newnode->right = NULL;
	newnode->data = k;
	return newnode;
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

node * generate(int a[],int n,stack<node *> s) {
	node* root = new node;
	root->left = root->right = NULL;
	root->data = a[0];
	node* p = root;
	for (int i = 1; i < n; i++) {
		if (a[i] < p->data) {
			newnode = make(p, a[i]);
			p->left = newnode;
			s.push(p);
			p = newnode;
		}
		else if (a[i] > p->data) {
			if (s.empty()) {
				newnode = make(p, a[i]);
				p->right = newnode;
				p = newnode;
			}
			else if (a[i] < s.top()->data) {
				newnode = make(p, a[i]);
				p->right = newnode;
				p = newnode;
			}
			else
			{
				p = s.top();
				s.pop();
				i--;

			}
		}
	}
	return root;
}

void main() {
	int a[100], n;
	cout << "Enter the elemets of a BST" << endl;
	cin >> n;
	cout << "Enter preorder traversal " << endl;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	stack <node*> s;

	preorder(generate(a,n,s));
	//node* root = NULL;
	//root = create(a[0],root);
	/*for (int i = 1; i < n; i++) {
		create(a[i], root);
	}*/

	//preorder(root); cout << endl;
	//search(root, 25) ? cout << "Found" << endl : cout<<"Not found"<<endl;
	//search(root, 30) ? cout << "Found" << endl : cout << "Not found" << endl;
	//delete_(root, 35);
	//cout << inorder_pred(root->left)->data << endl;
	//cout << inorder_succ(root -> right)->data << endl;

}