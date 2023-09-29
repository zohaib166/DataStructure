#include <iostream>
using namespace std;

typedef struct _node {
    int data;
    struct _node *next;
} Node;

Node *front = NULL, *rear = NULL;

void nq(int num) {
    Node *n = new Node;
    n->data = num;
    n->next = NULL;
    if(front==NULL && rear==NULL) {
        front = rear = n;
        return;
    }
    rear->next = n;
    rear = n;
}

int dq() {
    if(front==NULL) {
        return -1;
    }
    Node *temp = front;
    int x = temp->data;
    front = front->next;
    free(temp);
    return x;
}

void display() {
    Node *temp = front;
    while(temp!=NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    } 
    cout << endl;
}
int main() {
    nq(10);
    nq(20);
    nq(30);
    nq(40);
    display();
    cout << dq() << " ";
    cout << dq() << endl;
    display();
}
