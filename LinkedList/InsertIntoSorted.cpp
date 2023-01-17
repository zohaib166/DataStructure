#include <cstdio>
#include <cstdlib>
using namespace std;

typedef struct _node {
    int data;
    struct _node *next;
} Node;

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

void insertInSorted(Node *t, int num) {
    Node *prev = t;
    while(t!=NULL && num > t->data) {
        prev = t;
        t = t->next;
    }
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = num;
    new_node->next = prev->next;
    prev->next = new_node;
}

void display(Node *t) {
    while(t) {
        printf("%d ", t->data);
        t=t->next;
    }
    printf("\n");
}
int main() {
    int A[10] = {3,6,9,13,17};
    create(A,5);
    display(head);
    insertInSorted(head,2);
    display(head);
}