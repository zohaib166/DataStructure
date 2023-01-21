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

void display(Node *p) {
    while(p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void insertDLL(Node *p, int pos, int value) {
    //create a node fill data
    Node *new_node = (Node*) malloc(sizeof(Node));
    new_node -> data = value;
    //make prev and next as NULL
    new_node->prev = new_node->next = NULL;
    //if the linked list does not exist ass first node
    if(p==NULL) {
        p = head = tail = new_node;
        return;
    } 
    //if node is to nbe inserted before head
    if(pos==1) {
        new_node->next = head;
        head = new_node;
    } else {
    //any other position
        int i = 1;
        while(i<pos) {
            p=p->next;
            i++;
        }
        new_node->prev = p;
        new_node->next = p->next;
        //if the position of insertion is last
        if(p->next!=NULL) {
            p->next->prev = new_node;
        }
        p->next = new_node;
        //let tail point the last node
        if(pos==5) {
            tail = new_node;
        }
    }
}

int main() {
    int A[] = {10,20,30,40,50};
    int size = 5;
    createDLL(A, size);
    insertDLL(head, 5, 9);
    display(head);
}