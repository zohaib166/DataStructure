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

void display(Node *p) {
    do {
        printf("%d ", p->data);
        p = p->next;
    } while(p!=head);
    printf("\n");
}

void insertCDLL(Node *p, int pos, int val) {
    Node *new_node;
    new_node = (Node*) malloc(sizeof(Node));
    new_node -> data = val;
    new_node -> prev = new_node -> next = NULL;
    if(pos == 1) {
        new_node->prev = p->prev;
        new_node->next = p;

        p->prev->next = new_node;
        p->prev = new_node;
        
        head = new_node;
    } else {
        int i = 1;
        while(i<pos-1) {
            p=p->next;
            i++;
        }
        new_node->prev = p;
        new_node->next = p->next;

        p->next->prev = new_node;
        p->next = new_node;

    }
}

int main() {
    int A[] = {10,20,30,40,50};
    int size = 5;
    createDLL(A, size);
    display(head);
    insertCDLL(head, 7, 3);
    display(head);
}
