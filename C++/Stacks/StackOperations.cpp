#include <iostream>
using namespace std;

typedef struct stack {
    int top;
    int capacity;
    int* array;
};
stack *stk;
stack * create_stack(int c) {
    stk = new stack;
    stk->top = -1;
    stk->capacity = c;
    stk->array = new int[stk->capacity];
    return stk;
}



bool is_Empty(stack* s) {
    if (s->top == -1) {
        return 1;
    }
    return 0;

}


int stackTop(stack* stk) {
    if (!is_Empty(stk)) {
        return stk->array[stk->top];
    }
}


bool is_full(stack* s) {
    if (s->top == s->capacity - 1) {
        return 1;
    }
    return 0;
}

void push(stack* stk,int data) {
    if (!is_full(stk)) {
        stk->top++;
        stk->array[stk->top] = data;
    }
    else
    {
        cout << "Stack Overflow" << endl;
    }
}

int peek(stack* stk,int pos) {
    if (stk->top - pos + 1 > 0) {
        return stk->array[stk->top - pos + 1];
    }
    return -1;

}

void pop(stack* stk) {
    if (!is_Empty(stk)) {
        stk->top--;
    }
    else
    {
        cout << "Stack is Empty" << endl;
    }
}




int main() {

    stk = create_stack(100);
    push(stk, 100);
    push(stk, 200);
    push(stk, 300);
    cout << stackTop(stk) << endl;
    cout << peek(stk, 1) << endl;
    pop(stk);
    pop(stk);
    pop(stk);

}