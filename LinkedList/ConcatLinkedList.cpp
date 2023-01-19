#include<iostream>
using namespace std;

typedef struct _node
{
    int data;
    struct _node *next;
} Node;


void create(Node **a, int A[], int n) {
    Node *t;
    int i;
    
    *a = (Node*)malloc(sizeof(Node));
    
    (*a) -> data = A[0];
    (*a) -> next = NULL;
    t = (*a);
    
    Node *temp;
    for(i=1; i<n; i++) {
        temp = (Node*)malloc(sizeof(Node));
        temp -> data = A[i];
        temp -> next = NULL;
        t -> next = temp;
        t = temp;
    }
}

Node* concatLinkedList(Node **a, Node **b) {
    Node *third = *a;
    Node *temp = *a;
    while (temp->next!=NULL) {
        temp = temp->next;
    }
    temp->next = *b;
    return third;
}

void display(Node *t) {
    while(t!=NULL) {
        printf("%d ", t->data);
        t = t -> next;
    }
    printf("\n");
}

int main()
{
    Node *first, *second = NULL;
    int A[10] = {1,5,8,10,15};
    create(&first, A, 5);
    display(first);
    int B[10] = {3,7,12,18,24};
    create(&second, B, 5);
    display(second);

    Node *third = concatLinkedList(&first, &second);
    display(third);
    return 0;
}