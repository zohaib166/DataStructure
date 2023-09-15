#include <cstdio>
#include <iostream>
using namespace std;

#define SIZE 10

typedef struct _stack {
    int data[SIZE];
    int top1 = -1;
    int top2 = SIZE;
} stack;

void push1(stack *s, int n) {
    s->top1++;
    if(s->top1 == s->top2) {
        cout << "Stack1 is Full" << endl;
        return;
    }
    s->data[s->top1] = n;
}

void push2(stack *s, int n) {
    s->top2--;
    if(s->top1 == s->top2) {
        cout << "Stack2 is Full" << endl;
        return;
    }
    s->data[s->top2] = n;
}

int pop1(stack *s) {
    if(s->top1==-1) {
        cout << "stack1 is empty" << endl;
        return -1;
    }
    cout << s->data[s->top1] << " ";
    return s->data[s->top1--];
}

int pop2(stack *s) {
    if(s->top2==SIZE) {
        cout << "stack2 is empty" << endl;
        return -1;
    }
    cout << s->data[s->top2] << " ";
    return s->data[s->top2++];
}

void top1(stack *s) {
    if(s->top1==-1) {
        cout << "\nstack1 is empty" << endl;
        return;
    } 
    cout << "\n" << s->data[s->top1] << " ";
}

void top2(stack *s) {
    if(s->top2==SIZE) {
        cout << "\nstack2 is empty" << endl;
        return;
    } 
    cout << "\n" << s->data[s->top2] << " ";
}

int empty(stack *s) {
    if(s->top1==-1 && s->top2) return 1;
    else return 0;
}


int main() {
    stack s;
    push1(&s, 10);
    push2(&s, 20);
    push1(&s, 30);
    push2(&s, 40);

    pop1(&s);pop2(&s);pop1(&s);
    top2(&s); top1(&s);
}
