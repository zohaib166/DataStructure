#include <cstdio>
#include <iostream>
using namespace std;

#define SIZE 10

typedef struct _stack {
    int data[SIZE];
    int top = -1;
} stack;

void push(stack *s, int n) {
    s->top++;
    if(s->top == SIZE-1) {
        cout << "Stack is Full" << endl;
        return;
    }
    s->data[s->top] = n;
}

int pop(stack *s) {
    if(s->top==-1) {
        cout << "stack is empty" << endl;
        return -1;
    }
    cout << s->data[s->top] << " ";
    return s->data[s->top--];
}

void top(stack *s) {
    if(s->top==-1) {
        cout << "\nstack is empty" << endl;
        return;
    } 
    cout << "\n" << s->data[s->top] << " ";
}

int empty(stack *s) {
    if(s->top==-1) return 1;
    else return 0;
}


int main() {
    stack s;
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    push(&s, 40);

    pop(&s);pop(&s);pop(&s);
    top(&s);
}
