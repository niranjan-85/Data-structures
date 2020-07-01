#include<bits/stdc++.h>
using namespace std;
typedef struct node {
	int data;
	node* left;
	node* right;
};
node* ptr, * temp, * root, * l, * r;


//Traverse the created tree 
void preorder(node* ptr) {
	if (ptr != NULL) {
		cout << ptr->data << " ";
		preorder(ptr->left);
		preorder(ptr->right);
	}
}

void inorder(node* ptr) {
	if (ptr != NULL) {
		inorder(ptr->left);
		cout << ptr->data << " ";
		inorder(ptr->right);
	}
}

void postorder(node* ptr) {
	if (ptr != NULL) {
		postorder(ptr->left);
		postorder(ptr->right);
		cout << ptr->data<<" ";
	}
}

void iterp(node* ptr) {
	stack <node*> stk;
	stk.push(ptr);
	while (!stk.empty()) {
		node* data = stk.top();
		cout << data->data<<" ";
		stk.pop();
		if (data->right) {
			stk.push(data->right);
		}
		if (data->left) {
			stk.push(data->left);
		}
	}
}

void iteri(node* ptr) {
	stack <node*> s;
	s.push(ptr);
	ptr = ptr->left;
	while (ptr || !s.empty()) {
		if (ptr) {
			s.push(ptr);
			ptr = ptr->left;
		}
		else
		{
			ptr = s.top();
			s.pop();
			cout << ptr->data << " ";
			ptr = ptr->right;
		}
	}
}


void iterpost(node* ptr) {
	stack <node*> s1,s2;
	s1.push(ptr);
	while (!s1.empty()) {
		node* pele = s1.top();
		s1.pop();
		s2.push(pele);
		if (pele->left) {
			s1.push(pele->left);
		}
		if (pele->right) {
			s1.push(pele->right);
		}
	}
	while (!s2.empty()) {
		cout << s2.top()->data<<" ";
		s2.pop();
	}

}

void levelorder(node * ptr){
	queue <node*> q;
	q.push(ptr);
	while (!q.empty()) {
		node* temp = q.front();
		cout << temp->data << " ";
		q.pop();
		if (temp->left) {
			q.push(temp->left);
		}
		if (temp->right) {
			q.push(temp->right);
		}
	}
}

void create(queue <node*> q, int* arr, int len) {
	int i = 0;
	root = new node;
	root->data = arr[i];
	root->left = root->right = NULL;
	q.push(root);
	while (((2 * i) + 2) < len) {
		ptr = q.front();
		q.pop();
		if (arr[(2 * i) + 1] != -1 && arr[i] != -1) {
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
	cout << "Inorder traversal "; inorder(root); cout << endl;
	cout << "Iterative Inorder traversal "; iteri(root); cout << endl;
	cout << "Preorder traversal "; iterp(root); cout << endl;
	cout << "Iterative Preorder traversal "; preorder(root); cout << endl;
	cout << "Postorder traversal ";postorder(root); cout << endl;
	cout << "Iterative Postorder traversal "; iterpost(root);cout<<endl;
	cout << "Levelorder traversal "; levelorder(root);
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
	create(bt_add, b_elements, n); //only a complete binary tree.

}