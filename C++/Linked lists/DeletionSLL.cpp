#include<iostream>
using namespace std;
typedef int I;
typedef struct node {
	I data;
	node* next;
};
node* head, * newnode, * temp,*del,*prevnode;


void display() {
	temp = head;
	while (temp!= NULL) {
		cout << temp->data << endl;;
		temp = temp->next;
	}
}

void delete_b() {
	I pos,x=1;
	del = head;
	cin >> pos;
	if (pos == 1) {
		head = del->next;
		free(del);
	}
	else
	{
		while (x < pos - 1) {
			del = del->next;
			x = x + 1;
		}
		prevnode = del;
		del = del->next;
		prevnode->next = del->next;
		free(del);
	}


}


void main() {
	I n = 3;
	head = NULL;
	while (n != 0) {

		newnode = (node*)malloc(sizeof(node));
		cout << "Enter data";
		cin >> newnode->data;
		if (head == NULL) {
			temp = head = newnode;
		}
		else
		{
			temp->next = newnode;
			temp = newnode;
		}
		temp->next = NULL;
		n = n - 1;
		
	}
	display();
	delete_b();
	display();
}