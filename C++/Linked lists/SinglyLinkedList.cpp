#include<iostream>
#include<stdlib.h>
using namespace std;
typedef int I;
typedef struct node {
	I data;
	node* next;
};
node* head,*newnode,*temp;
void main() {
	I n=3;
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
		temp->next=newnode;
		newnode->next=NULL;
		n = n - 1;
	}
	temp = head;
	while(temp!=NULL) {
		cout << temp->data<<endl;
		cout << temp->next << endl;;
		temp = temp->next;
	}


}
