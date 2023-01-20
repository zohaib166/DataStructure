#include <cstdio>
#include <cstdlib>

typedef struct _node
{
    int data;
    struct _node *next;
} Node;

Node *head = NULL;

void create(int A[], int size) {
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

/**static variable 'flag' will check whether pointer 't'
is visiting head for the second time or not*/
void display_recur(Node *t) {
    static int flag = 0;
    if(t!=head || flag==0) {
        flag = 1;
        printf("%d ", t->data);
        display_recur(t->next);
    }
    flag = 1;
}

int main() {
    int A[] = {3,4,5,6,7};
    int size = 5;
    create(A, size);
    //display(head);
    display_recur(head);
}