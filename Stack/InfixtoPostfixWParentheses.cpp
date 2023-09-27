#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

typedef struct _stack {
    char *data;
    int size;
    int top = -1;
} stack;

void init(stack *s, int size) {
    s->size = size;
    s->data = (char*) malloc(sizeof(char)*size);
}

void push(stack *s, int n) {
    s->top++;
    if(s->top == s->size-1) {
        cout << "Stack is Full" << endl;
        return;
    }
    s->data[s->top] = n;
}

int pop(stack *s) {
    if(s->top==-1) {
        //cout << "stack is empty" << endl;
        return -1;
    }

    return s->data[s->top--];
}

int top(stack *s) {
    if(s->top==-1) {
        //cout << "\nstack is empty" << endl;
        return -1;
    }
    return s->data[s->top];
}

int empty(stack *s) {
    if(s->top==-1) return 1;
    else return 0;
}

int isOperator(char x) {
    switch (x)
    {
        case '+':
        case '-':
        case '*':
        case '/':
            return 1;
        default:
            return 0;
    }
}

int getPrecedence(char x) {
    switch(x) {
        case '+':
        case '-':
            return 5;
        case '*':
        case '/':
            return 7;
        default:
            return 0;
    }
}

void infix2postfix(const char *infix, char *postfix) {
    int i=0,j=0;
    stack s;
    init(&s, strlen(infix));
    while(infix[i]!='\0') {
        if((infix[i]!='(' && infix[i]!=')') && !isOperator(infix[i])) {
            postfix[j++] = infix[i];
        } else if(infix[i]=='(') {
            push(&s, infix[i]);
        } else if(infix[i]==')') {
            while(!empty(&s) && top(&s)!='(') {
                postfix[j++] = pop(&s);
            }
            if(!empty(&s) && top(&s)!='(') {
                printf("Invalid Expression\n");
                return;
            } else {
                pop(&s);
            }
        } else if(isOperator(infix[i])) {
            while(!empty(&s) || getPrecedence(infix[i]) <= getPrecedence(top(&s))) {
                postfix[j++] = pop(&s);
            } 
            push(&s, infix[i]);
        }
        i++;
    }

    while(!empty(&s)) {
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0';
}

int main() {
    const char *infix = "(a+b)*c";
    char *postfix = new char[strlen(infix)+1];
    infix2postfix(infix, postfix);
    printf("%s", postfix);
}
