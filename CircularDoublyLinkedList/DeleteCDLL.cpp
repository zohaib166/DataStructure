#include <cstdio>
#include <cstdlib>

typedef struct dll {
    struct dll *prev;
    int data;
    struct dll *next;
} Node;

Node *head=NULL;

void createDLL(int A[], int size) {
    Node *p = NULL;
    Node *new_node = (Node*) malloc(sizeof(Node));
    new_node->data = A[0];
    new_node->next = new_node->prev = NULL;
    p = head = new_node;
    for(int i=1; i<size; i++) {
        new_node = (Node*) malloc(sizeof(Node));
        new_node->data = A[i];
        new_node->prev = p;
        p->next = new_node;
        new_node->next = NULL;
        p=p->next;
    }
    p->next = head;
    head->prev = p;
}

void deleteCDLL(Node *p, int pos) {
    int i = 1;
    while(i<pos) {
        p=p->next;
        i++;
    }
    p->next->prev = p->prev;
    p->prev->next = p->next;
    if(i==1)
        head = p->next;
    p->prev = p->next = NULL;
    free(p);
}

void display(Node *p) {
    do {
        printf("%d ", p->data);
        p = p->next;
    } while(p!=head);
    printf("\n");
}

int main() {
    int A[] = {10,20,30,40,50};
    int size = 5;
    createDLL(A, size);
    display(head);
    deleteCDLL(head, 5);
    display(head);
}
