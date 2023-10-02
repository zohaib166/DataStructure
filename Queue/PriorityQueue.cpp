#include <iostream>
using namespace std;

typedef struct _node {
    int data;
    int priority; //low number = high priority
    struct _node *next;
} Node;

Node *head = NULL;

Node *createNode(int num, int pri) {
    Node *n = new Node;
    n->data = num;
    n->priority = pri;
    n->next = NULL;
    return n;
}

void push(Node *p, int num, int pri) {
    Node *new_node = createNode(num, pri);
    if(p==NULL) {
        head = new_node;
        return;
    }
    if(head->priority > pri) {
        new_node->next = head;
        head = new_node;
        return;
    }
    while(p->next!=NULL && p->next->priority < pri) {
        p=p->next;
    }
    new_node->next = p->next;
    p->next = new_node;
}

void pop(Node *p) {
    head = head->next;
    free(p);
}

void display(Node *p) {
    while(p!=NULL) {
        cout << p->data << ":" << p->priority << "\t";
        p=p->next;
    }
    cout << endl;

}

int main() {
    push(head, 10, 1);
    push(head, 12, 4);
    push(head, 13, 2);
    push(head, 14, 3);

    display(head);

    pop(head);

    display(head);
}
