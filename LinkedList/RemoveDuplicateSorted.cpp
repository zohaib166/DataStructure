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

void removeDuplicate(Node *p) {
    Node *prev = p;
    p=p->next;
    while(p) {
        if(prev->data == p->data) {
            prev->next=p->next;
            free(p);
            p = prev->next;
        } else {
            prev = p;
            p=p->next;
        }
    }
}

void display(Node *t) {
    while(t!=NULL) {
        printf("%d ", t->data);
        t = t -> next;
    }
    printf("\n");
}


int main()
{
    int A[10] = {2,2,4,6,6};
    create(A,5);
    display(head);
    removeDuplicate(head);
    display(head);
    return 0;
}