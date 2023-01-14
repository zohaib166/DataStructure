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

int addNodes(Node *t) {
    int sum=0;
    while(t!=NULL) {
        sum+=t->data;
        t=t->next;
    }
    return sum;
}

int rAddNodes(Node *t) {
    if(t!=NULL) {
        return rAddNodes(t->next) + t->data;
    } else {
        return 0;
    }
}

int main()
{
    int A[10] = {2,3,4,5,6};
    create(A,5);
    //printf("%d ", addNodes(head));
    printf("%d ", rAddNodes(head));
    return 0;
}