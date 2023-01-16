#include <cstdio>
#include <cstdlib>

typedef struct _node
{
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

void display(Node *t) {
    while(t!=NULL) {
        printf("%d ", t->data);
        t = t -> next;
    }
    printf("\n");
}

Node* improvedSearch(Node *t, int key) {
    Node *prev = NULL;
    while(t) {
        if(t->data == key) {
            prev->next = t->next;
            t->next = head;
            head = t;
            return t;
        }
        prev = t;
        t = t->next;
    }
    return NULL;
}

int main()
{
    int A[10] = {12,3,14,5,6};
    create(A,5);
    display(head);
    Node *t = improvedSearch(head, 14);
    display(head);
    t = improvedSearch(head, 6);
    display(head);
    return 0;
}