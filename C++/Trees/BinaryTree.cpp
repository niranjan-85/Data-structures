#include<bits/stdc++.h>
using namespace std;
typedef struct node {
	int data;
	node* left;
	node* right;
};
node*ptr,* temp,*root,*l,*r;


//Traverse the created tree 
void preorder(node* root) {
	ptr = root;
	if(ptr) {
		cout << ptr->data << endl;
		preorder(root->left);
		preorder(root->right);
	}
}


void create(queue <node*> q,int *arr,int len) {
	int i = 0;
	root = new node;
	root->data = arr[i];
	root->left = root->right = NULL;
	q.push(root);
	while (((2 * i) + 2) < len ) {
		ptr = q.front();
		q.pop();
		if (arr[(2 * i) + 1] != -1 && arr[i]!=-1) {
			l = new node;
			l->data = arr[(2 * i) + 1];
			l->left = l->right = NULL;
			ptr->left = l;
			q.push(l);
		}
		if (arr[(2 * i) + 2] != -1 && arr[i] != -1) {
			r = new node;
			r->data = arr[(2 * i) + 2];
			r->left = r->right = NULL;
			ptr->right = r;
			q.push(r);
		}
		i++;
	}
	preorder(root);
}



void main() {
	//Array representation of the binary tree
	int* b_elements = new int[100];
	int n; std::cout << "Enter no of elements"; std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> b_elements[i];
	}
	//queue to store the adresses
	queue <node*> bt_add;
	create(bt_add,b_elements,n);

}
