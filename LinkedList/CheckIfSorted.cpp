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

int checkIfSorted(Node *p) {
    int temp = INT_MIN;
    while(p) {
        if(p->data > temp) {
            temp = p->data;
        } else {
            return 0;
        }
        p=p->next;
    }
    return 1;
}

int main()
{
    int A[10] = {2,3,4,5,6};
    create(A,5);
    if(checkIfSorted(head)) {
        printf("Sorted");
    } else {
        printf("Not Sorted");
    }
    return 0;
}