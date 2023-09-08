#include <cstdio>
#include <iostream>
using namespace std;

typedef struct _node {
    int data;
    struct _node *next;
} Node;

typedef struct _stack
{
    Node *top = NULL;
} stack;

void push(stack *s, int n) {
    Node *temp;
    temp = (Node*) malloc(sizeof(Node));
    temp->data = n;
    temp->next = NULL;
    
    if(s->top==NULL) {
        s->top = temp;
        return;
    } 
    temp->next = s->top;
    s->top = temp;
}

void top(stack *s) {
    if(s->top==NULL) {
        cout << "Stack is empty" << endl;
        return;
    } 
    cout <<  s->top->data << " ";
}

void pop(stack *s) {
    if(s->top==NULL) {
        cout << "Stack is empty" << endl;
        return;
    }
    Node *temp = s->top;
    s->top = s->top->next;
    free(temp); 
}

int main() {
    stack s;
    push(&s, 10);
    push(&s, 11);
    push(&s, 12);
    push(&s, 13);
    top(&s); pop(&s); top(&s); pop(&s); top(&s); pop(&s); top(&s); pop(&s); top(&s);
}
