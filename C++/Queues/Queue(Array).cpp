#include<bits/stdc++.h>
using namespace std;

typedef struct Queue {
	int capacity,front,rear;
	int *array;
};

Queue* create(int size) {
	// create a queue in heap.
	Queue *q = new Queue;
	//Initialize front=rear;
	q->front = q->rear = -1;
	q->capacity = size;
	q->array = new int[q->capacity];
	return q;
}

bool isempty(Queue *q) {
	if (q->front == q->rear) {
		return 1;
	}
	return 0;
}

bool isFull(Queue * q) {
	if (q->rear == q->capacity - 1) {
		return 1;
	}
	return 0;
}

//enqueue operation.

void insert(int dt,Queue *q) {
	if (!isFull(q)) {
		q->rear++;
		q->array[q->rear] = dt;
	}
	else
	{
		cout << "Queue is full cannot insert";
	}
}

//dequeue operation.

int delete_q(Queue * q) {
	int x = 0;
	if (!isempty(q)) {
		q->front++;
		x = q->array[q->front];
	}return x;
}

// display the elements of queue.
void display(Queue *q) {
	int temp = q->front+1;
	while (temp != q->rear + 1) {
		cout << q->array[temp]<<endl;
		temp++;
	}
}

void main() {
	// Create a queue having size 10.
	Queue *q = create(10);

	insert(100, q);
	insert(200, q);
	insert(300, q);
	insert(400, q);
	delete_q(q) ? cout<<"deleted item "<<endl: cout << "Cannot delete"<<endl;
	display(q);
	delete_q(q) ? cout << "deleted item " << endl : cout << "Cannot delete" << endl;
	display(q);

}