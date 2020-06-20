#include<bits/stdc++.h>
using namespace std;
typedef struct node {
	int data;
	node* next;
};

node* front, * rear, * temp, * newnode;

void insert(int data) {
	newnode = new node;
	newnode->data = data;
	if (front == NULL) {
		front = rear = newnode;
	}
	else {
		rear->next = newnode;
		rear = newnode;
	}
	newnode->next = NULL;
}

void del() {
	temp = front;
	if (front != NULL) {
		front = front->next;
		delete(temp);
	}
	else
	{
		cout << "Queue is empty cannot delete" << endl;
	}
}


void display() {
	temp = front;
	while (temp != NULL) {
		cout << temp->data <<endl;
		temp = temp->next;
	}
}


void main() {
	front = rear = NULL;
	insert(100);
	insert(200);
	insert(400);
	del();
	del();
	del();
	del();
	display();
}