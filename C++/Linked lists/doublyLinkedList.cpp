#include<bits/stdc++.h>
using namespace std;
typedef struct node {
	int data;
	node* previous, * next;
};
node* temp, * head,*newnode;

void display() {
	temp = head;
	while (temp != NULL) {
		cout << temp->data << endl;
		temp = temp->next;

	}

}

void insert(int pos) {
	newnode = new node;
	cout << "Enter data" << endl;
	cin >> newnode->data;
	temp = head;
	if (pos == 0) {
		temp->previous = newnode;
		newnode->next = head;
		newnode->previous = NULL;
		head = newnode;
	}
	else
	{
		int x = 0;
		while (x < pos - 1) {
			temp = temp->next;
			x++;
		}
		newnode->next = temp->next;
		newnode->previous = temp;
		if (temp->next != NULL) {
			temp->next->previous = newnode;
		}
		temp->next = newnode;
	}
}


void main() {
	int n,p;
	cout << "Enter no of nodes" << endl;
	cin >> n;
	head = NULL;
	while (n--) {
		newnode = new node;
		cout << "Enter data" << endl;
		cin >> newnode->data;
		if (head == NULL) {
			temp = head = newnode;
			newnode->previous = NULL;
		}
		else{
			newnode->previous = temp;
			temp->next = newnode;
			temp = newnode;
		}
		temp->next = NULL;
	}
	display();
	cout << "Enter position " << endl;
	cin >> p;
	insert(p);
	display();
}