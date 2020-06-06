#include<iostream>
using namespace std;
typedef struct node {
	int data;
	node* next;
};
node* head, * newnode, * temp,*t1,*t2;

void sort() {
	int sp;
	t1 = t2 = head;
	while (t1!=NULL){
		t2 = t1->next;
		while (t2!=NULL){
			if (t2->data < t1->data) {
				sp = t2->data;
				t2->data = t1->data;
				t1->data = sp;
			}
			t2 = t2->next;
		}
		t1 = t1->next;
	}

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
	sort();
	display();

}