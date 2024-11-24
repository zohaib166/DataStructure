#include <iostream>
using namespace std;
#define SIZE 10

class stack {
    public:
    int size;
    int top;
    int *arr;

    stack() {
        top = -1;
        this->size = SIZE;
        arr = new int[size];
    }
    
    void push(int data) {
        if(top==size-1) {
            cout << "stack is full" << endl;
            return;
        }
        arr[++top] = data;
    }
    
    void pop() {
        if(top==-1) {
            cout << "stack is empty" << endl;
            return;
        }
        top--;
    }
    
    int gettop() {
        if(top==-1) {
            cout << "stack is empty" << endl;
            return top;
        }
        return arr[top];
    }
};

class multistack {
    public:
    stack *s;
    int count;
    multistack(int count) {
        this->count = count;
        s = new stack[count];
    }
    
    void push(int stacknum, int data) {
        s[stacknum].push(data);
    }
    
    void pop(int stacknum) {
        s[stacknum].pop();
    }
    
    int top(int stacknum) {
        return s[stacknum].gettop();
    }
};

int main()
{
    multistack ms(3);
    ms.push(0,12);
    ms.push(0,13);
    ms.push(0,14);
    
    ms.push(1,15);
    ms.push(1,24);
    ms.push(1,45);
    
    ms.push(2,10);
    ms.push(2,20);
    ms.push(2,30);
    
    ms.pop(1);
    
    cout << ms.top(0) << endl;
    cout << ms.top(1) << endl;
    cout << ms.top(2) << endl;
    
    
}