#include <cstdio>
#include <iostream>
#include <cstring>
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

int top(stack *s) {
    if(s->top==NULL) {
        cout << "Stack is empty" << endl;
        return -1;
    } 
    return s->top->data;
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

int empty(stack *s) {
    if(s->top==NULL) {
        return 1;
    }
    return 0;
}

int main() {
    stack s;
    char expr[] = "84-4/3+";
    int num1, num2;
    for(int i=0;i<strlen(expr);i++) {
        if(isdigit(expr[i])) {
            //printf("digit: %c\n",expr[i]);
            push(&s, expr[i]-48);
        } else {
            
            num2 = top(&s); pop(&s);
            num1 = top(&s); pop(&s);
            printf("num2: %d; num1: %d\n", num2, num1);
            switch(expr[i]) {
                case '+':
                    push(&s, num1+num2);
                    break;
                case '-':
                    push(&s, num1-num2);
                    break;
                case '*':
                    push(&s, num1*num2);
                    break;
                case '/':
                    push(&s, num1/num2);
                    break;
            }
            
        }
    }
    printf("%d", top(&s));
}
