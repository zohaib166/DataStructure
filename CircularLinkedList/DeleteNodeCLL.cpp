#include <cstdio>
#include <cstdlib>

typedef struct _node
{
    int data;
    struct _node *next;
} Node;

Node *head = NULL;

void createCLL(int A[], int size) {
    Node *temp, *new_node;
    head = (Node*) malloc(sizeof(Node));
    temp = head;
    temp->data = A[0];
    temp->next = NULL;
    for(int i=1; i<size; i++) {
        new_node = (Node*) malloc(sizeof(Node));
        temp->next = new_node;
        new_node->data = A[i];
        temp = temp->next;
    }
    //Link back to head
    temp->next = head;
}

void display(Node *t) {
    do {
        printf("%d ", t->data);
        t=t->next;
    } while(t!=head);
    printf("\n");
}

void deleteNode(Node *p, int pos) {
    if(p==NULL) {
        return;
    }
    if(pos==1) {
        do {
            p=p->next;
        } while(p->next!=head);
        p->next = head->next;
        free(head);
        head = p->next;
    } else {
        Node *q = NULL;
        int i=1;
        while(i<pos) {
            q = p;
            p = p->next;
            i++;
        }
        q->next = p->next;
        free(p);
    }
}

int main() {
    int A[] = {10,20,30,40,50};
    int size = 5;
    createCLL(A, size);
    display(head);
    deleteNode(head, 5);
    display(head);
}