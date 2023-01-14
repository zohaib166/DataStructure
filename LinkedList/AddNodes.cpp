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

int addNodes(Node *head) {
    Node *t = head;
    int sum=0;
    while(t!=NULL) {
        sum+=t->data;
        t=t->next;
    }
    return sum;
}

int main()
{
    int A[10] = {2,3,4,5,6};
    create(A,5);
    printf("%d ", addNodes(head));
    return 0;
}