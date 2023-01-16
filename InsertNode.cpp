#include <cstdio>
#include <cstdlib>
using namespace std;

typedef struct _node {
    int data;
    struct _node *next;
} Node;


Node *head = NULL;

void create(int A[], int size) {
    Node *t = NULL;
    if(head==NULL) {
        head = (Node*)malloc(sizeof(Node));
        t = head;
        t->data = A[0];
        t->next = NULL;
    }
    Node *temp = NULL;
    for(int i=1; i<size; i++) {
        temp = (Node*)malloc(sizeof(Node));
        temp -> data = A[i];
        temp -> next = NULL;
        t -> next = temp;
        t = temp;
    }
}

int countNodes(Node *t) {
    int count=0;
    while(t!=NULL) {
        count++;
        t=t->next;
    }
    return count;
}

void insertNode(Node *t, int pos, int value) {
    if(pos<0 || pos>countNodes(t)) {
        return;
    }
    for(int i=1; i<pos-1; i++) {
        t=t->next;
    }
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->data = value;
    temp->next = t->next;
    t->next = temp;
}

void display(Node *t) {
    while(t) {
        printf("%d ", t->data);
        t=t->next;
    }
    printf("\n");
}
int main() {
    int A[] = {4,8,9,11,14,16,18,21,25,34};
    int size = 10;
    create(A, 10);
    display(head);
    insertNode(head, 5, 99);
    display(head);
}