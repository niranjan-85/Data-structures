#include<iostream>
using namespace std;
int n;
int k;
struct node {
	int data;
	struct node* next;
}*newnode,*head,*temp,*ins,*end,*pos,*new2;
void create() {
	head = NULL;
	cout << "Enter no of nodes" << endl;;
	cin >> k;
	n = k;
	while (n!=0){
		newnode = (struct node*)malloc(sizeof(struct node));
		cout << "Enter data ";
		cin >> newnode->data;
		if (head == NULL) {
			head = temp = newnode;
			
		}
		else {
			temp->next = newnode;
			temp = newnode;
		}
		temp->next = NULL;
		n = n - 1;
	}

}

void insert() {
	cout << "Inserting a node at beginning" << endl;
	ins = (struct node*)malloc(sizeof(struct node));
	cout << "Enter data" << endl;
	cin >> ins->data;
	ins->next = head;
	head = ins;
}

void insert_end() {
	struct node *end,*trav;
	trav=head;
	end = (struct node*)malloc(sizeof(struct node));
	cout << "Enter data" << endl;
	cin >> end->data;
	while(trav->next != 0) {
	      trav = trav->next;
	}
	trav->next = end;
	end->next = 0;

}

void insert_atgivenpos() {
	pos = head;
	new2 = (struct node*)malloc(sizeof(struct node));
	int count,z=1;
	cout << "Enter the position"<<endl;
	cin >> count;
	cout << "Enter data" << endl;
	cin >> new2->data;
	while (z<count){
		pos = pos->next;
		z++;
	}
	new2->next = pos->next;
	pos->next = new2;

	

}


void display() {
	temp = head;
	while (temp != NULL) {
		cout << temp->data << endl;
		temp = temp->next;
	}
}


void  main() {
	int choice;
	cout << "****************** Linked list Operations ******************" << endl;
	cout << "1. Create a linked list" << endl;
	cout << "2. Display the created linked list" << endl;
	cout << "3. Insert a node in beginning of linked list" << endl;
	cout << "4. Insert a node at the end of linked list" << endl;
	while (1){
		cout << "Enter choice from 1-9" << endl;
		cin >> choice;
		switch (choice){
		case 1: {
			create();              //creation of linked list 
			break;
		}
		case 2: {
			display();             //displays the list
			break;
		}
		case 3: {
			insert();              //inserts node at beginning
			break;
		}
		case 4: {
			insert_end();
			break;
		}
		case 5: {
			insert_atgivenpos();
			break;
		}
		}

	}
}