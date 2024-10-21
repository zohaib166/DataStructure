#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
Node *head = NULL;

void create(int A[], int n) {
    Node *t;
    int i;
    head = (Node*)malloc(sizeof(Node));
    head -> data = A[0];
    head -> next = NULL;
    t = head;
    Node *temp;
    for(i=1; i<n; i++) {
        temp = (Node*)malloc(sizeof(Node));
        temp -> data = A[i];
        temp -> next = NULL;
        t -> next = temp;
        t = temp;
    }
}

void zigzag(Node *p) {
    bool flag = true;
    while(p->next!=NULL) {
        if(flag) {
            if(p->data > p->next->data) {
                swap(p->data, p->next->data);
            }
        } else {
            if(p->data < p->next->data) {
                swap(p->data, p->next->data);
            }
        }
        p=p->next;
        flag = !flag;
    }
}

//Iterative traversal
void display_iter(Node *t) {
    while(t!=NULL) {
        printf("%d ", t->data);
        t = t -> next;
    }
    cout << endl;
}

int main()
{
    int A[10] = {2,3,4,5,6,7,8};
    create(A,7);
    display_iter(head);

    zigzag(head);

    display_iter(head);
    return 0;
}