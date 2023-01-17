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

int countNodes(Node *t) {
    int count=0;
    while(t!=NULL) {
        count++;
        t=t->next;
    }
    return count;
}

void deleteNode(Node *t, int pos) {
    if(pos<0 || pos>countNodes(t)) return;
    Node *prev = t;
    int i;
    if(pos==1) {
        head = t->next;
        free(t);
        return;
    } else {
        //traverse the nodes 2 less than total number of nodes
        for(i=0; i<pos-1; i++) {
            prev = t;
            t = t->next;
        }
    }
    prev->next = t->next;
    free(t);
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
    deleteNode(head, 5);
    display(head);
}