#include<iostream>
using namespace std;
typedef struct node {
	int data;
	node* next;
};
node* head, * newnode, * temp,* prevnode, * nextnode, * current_node;;

void reverse() {
	prevnode = NULL;
	current_node = nextnode = head;
	while (nextnode != NULL) {
		nextnode = nextnode->next;
		current_node->next = prevnode;
		prevnode = current_node;
		current_node = nextnode;
	}
	head = prevnode;
}

void display() {
	temp = head;
	while (temp!=NULL){
		cout << temp->data<<endl;
		temp = temp->next;
	}
}

void main() {
	head = NULL;
	int n;
	cout << "Enter the no of nodes ";
	cin >> n;
	while (n!=0){
		newnode = (node*)malloc(sizeof(node));
		cout << "Enter data" << endl;
		cin >> newnode->data;
		if (head == NULL) {
			temp = head = newnode;
		}
		else{
			temp->next = newnode;
			temp = newnode;
		}
		temp->next = NULL;
		n--;
	}
	reverse();
	display();

}