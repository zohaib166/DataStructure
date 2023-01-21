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

void insertNode(Node *p, int pos, int value) {
    //create a new node and fill data in it
    Node *new_node;
    new_node = (Node*) malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = NULL;
    //if the node is to be inserted before head node
    if(p==NULL) {
        new_node->next = new_node;
        head = new_node;
        return;
    }
    if(pos==0) {
        while(p->next!=head) {
            p=p->next;
        }
        p->next = new_node;
        new_node->next = head;
        head = new_node;
    } else {
        int i = 1;
        while(i<pos) {
            p=p->next;
            i++;
        }
        new_node->next = p->next;
        p->next = new_node;
    }
}
void display(Node *t) {
    do {
        printf("%d ", t->data);
        t=t->next;
    } while(t!=head);

    printf("\n");
}

int main() {
    int A[] = {3,4,5,6,7};
    int size = 5;
    //createCLL(A, size);
    //display(head);
    insertNode(head, 3, 10);
    display(head);
}
