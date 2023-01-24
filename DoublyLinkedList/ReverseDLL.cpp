#include <cstdio>
#include <cstdlib>

typedef struct dll {
    struct dll *prev;
    int data;
    struct dll *next;
} Node;

Node *head=NULL, *tail=NULL;

void createDLL(int A[], int size) {
    Node *p = NULL;
    Node *new_node = (Node*) malloc(sizeof(Node));
    new_node->data = A[0];
    new_node->next = new_node->prev = NULL;
    p = head = tail = new_node;
    for(int i=1; i<size; i++) {
        new_node = (Node*) malloc(sizeof(Node));
        new_node->data = A[i];
        new_node->prev = p;
        p->next = new_node;
        new_node->next = NULL;
        p=p->next;
        tail = p;
    }
}

void reverseDLL(Node *p) {
    Node *temp = NULL;
    while(p!=NULL) {
        //swap the prev and next pointers
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        //move to next node
        p = p->prev;
        //check if p is not pointing to NULL and the next node is not NULL
        if(p!=NULL && p->next==NULL) {
            head = p;
        }
    }
}

void display(Node *p) {
    while(p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main() {
    int A[] = {10,20,30,40,50};
    int size = 5;
    createDLL(A, size);
    display(head);
    reverseDLL(head);
    display(head);
}