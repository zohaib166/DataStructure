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

Node* mergeLinkedList(Node **first, Node **second) {
    Node *third = NULL, *temp = NULL;
    if((*first)->data < (*second)->data) {
        third = temp = (*first);
        (*first) = (*first)->next;
        third->next = NULL;
    } else {
        third = temp = (*second);
        (*second) = (*second)->next;
        third->next = NULL;
    }

    while((*first) && (*second)) {
        if((*first)->data < (*second)->data) {
            temp->next = (*first);
            temp = (*first);
            *first = (*first)->next;
            temp -> next = NULL;
        } else {
            temp->next = (*second);
            temp = (*second);
            *second = (*second)->next;
            temp -> next = NULL;
        }
    }
    if((*first)==NULL) {
        temp->next = (*second);
    } else {
        temp->next = (*first);
    }
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

    Node *third = mergeLinkedList(&first, &second);
    display(third);
    return 0;
}