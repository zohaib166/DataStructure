#include <iostream>
using namespace std;

struct Node {
    char data;
    Node *next;
};

struct stack {
    Node *top = nullptr;  
};

stack s;

void push(char data) 
{
    Node *n = new Node;
    n->data = data;
    n->next = nullptr;
    if(s.top==nullptr) {
        s.top = n;
        return;
    }
    n->next = s.top;
    s.top = n;
}

char pop()
{
    if(s.top==nullptr) {
        cout << "Stack is empty\n";
        return '0';
    }
    Node *temp = s.top;
    int x = temp->data;
    s.top = s.top->next;
    delete temp;
    return x;
}

char top()
{
    if(s.top==nullptr) {
        return '0';
    }
    return s.top->data;
}

int main()
{
    string str = "([][]{}())";
    for(int i=0;i<str.length();i++)
    {
        if(str[i]=='(' || str[i]=='{' || str[i]=='[') {
            push(str[i]);
        } else if(str[i]==')' || str[i]=='}' || str[i]==']') {
            if(str[i]==')' && s.top->data=='(') {
                pop();
            } else if(str[i]=='}' && s.top->data=='{') {
                pop();
            } else if(str[i]==']' && s.top->data=='[') {
                pop();
            } else {
                cout << "brackets mismatch\n";
                return 0;
            }
        }
    }
    if(s.top!=nullptr) {
        cout << "brackets mismatch\n";
    } else {
        cout << "brackets matched\n";
    }
}

    