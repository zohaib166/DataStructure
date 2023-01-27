#include<iostream>
#include <stack>
using namespace std;

typedef struct _node
{
    int data;
    struct _node *next;
} Node;
Node *first = NULL, *second = NULL;

void createLL1(int A[], int n) {
    Node *t;
    int i;
    first = (Node*)malloc(sizeof(Node));
    first -> data = A[0];
    first -> next = NULL;
    t = first;
    Node *temp;
    for(i=1; i<n; i++) {
        temp = (Node*)malloc(sizeof(Node));
        temp -> data = A[i];
        temp -> next = NULL;
        t -> next = temp;
        t = temp;
    }
}

void createLL2(int A[], int n) {
    Node *t;
    int i;
    second = (Node*)malloc(sizeof(Node));
    second -> data = A[0];
    second -> next = NULL;
    t = second;
    Node *temp;
    for(i=1; i<n; i++) {
        temp = (Node*)malloc(sizeof(Node));
        temp -> data = A[i];
        temp -> next = NULL;
        t -> next = temp;
        t = temp;
    }
}

void display(Node *t) {
    while(t!=NULL) {
        printf("%d ", t->data);
        t = t -> next;
    }
    printf("\n");
}

int findIntersection(Node *p, Node *q) {
    stack<int> s1, s2;
    int common;
    while(p) { 
        s1.push(p->data);
        p = p->next;
    }
    while(q)
    {
        s2.push(q->data);
        q = q->next;
    }
    
    while(s1.top()==s2.top()) {
        common = s1.top();
        s1.pop(); s2.pop();
    }

    return common;
}

int main()
{
    int A[10] = {2,3,4,5,6,8,11};
    createLL1(A,7);
    printf("First Linked List: \n");
    display(first);
    int B[3] = {12,13,14};
    
    createLL2(B,3);
    //display(second);
    //Connect second linked list to the 4th node of first Linked List
    Node *p = first;
    for(int i=0;i<3;i++) {
        p=p->next;
    }
    Node *q = second;
    while(q->next!=NULL) {
        q=q->next;
    }
    q->next = p;
    printf("Second Linked List: \n");
    display(second);

    //find intersection
    printf("The linked lists intersect at %d ", findIntersection(first, second));
    return 0;
}