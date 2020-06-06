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

void del_node(int p) {
	temp = head;
	node* ptr = head;
	int x = 1;
	if (p == 1) {
		if(temp->next==NULL){
			delete(temp);
			head=NULL;
		}
		else{
			head = ptr = temp->next;
			ptr->previous=NULL;
			delete(temp);
			temp = head;
		}
	}
	else
	{
		while (x < p - 1) {
			temp = temp->next;
			x++;
		}
		ptr = temp->next;
		if (ptr->next != NULL) {
			temp->next = ptr->next;
			ptr->next->previous = temp;
		}
		else
		{
			delete(ptr);
			temp->next = NULL;
		}
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
	cin >> p;         // index :  0:length(list)-1
	del_node(p+1);
	display();
}
