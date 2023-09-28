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

char pop(stack *s) {
    if(s->top==-1) {
        return -1;
    }

    return s->data[s->top--];
}

char top(stack *s) {
    if(s->top==-1) {
        return -1;
    }
    return s->data[s->top];
}

int empty(stack *s) {
    if(s->top==-1) return 1;
    else return 0;
}

int getPrecedence(char op)
{
	switch (op) {
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	case '^':
		return 3;
	default: 
		return -1;
	}
}

int isOperator(char ch)
{
	return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch=='(' || ch==')');
}

void infix2postfix(const char *infix, char *postfix) {
    int i=0,j=0;
    stack s;
    int len = strlen(infix);
    init(&s, len);
    for (i = 0, j = 0; i < len; i++) {
        if(!isOperator(infix[i])) {
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
            while(!empty(&s) && getPrecedence(infix[i]) <= getPrecedence(top(&s))) {
                postfix[j++] = pop(&s);
            } 
            push(&s, infix[i]);
        }
    }

    while(!empty(&s)) {
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0';
}

int main() {
    const char *infix = "a*(b+c)";
    char *postfix = new char[strlen(infix)+2];
    infix2postfix(infix, postfix);
    printf("%s", postfix);
}

