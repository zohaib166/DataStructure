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

int countNodes(Node *t) {
    int count=0;
    while(t!=NULL) {
        count++;
        t=t->next;
    }
    return count;
}

//Reverse Linked List using sliding pointers r q and p
void reverseLinkedList(Node *p) {
    Node *q=NULL, *r=NULL;
    while(p!=NULL) {
        r = q;
        q = p;
        p = p -> next;
        q -> next = r;
    }
    head = q;
}

//Reversing Linked List using recursion
void reverseLL_recur(Node *q, Node *p) {
    if(p!=NULL) {
        reverseLL_recur(p, p->next);
        p->next = q;
    } else {
        head = q;
    }
}

//Reversing the contents in a linked list using array
void reverseLLContent(Node *p) {
    int *A, i=0;
    A = (int *) malloc (countNodes(p)*sizeof(Node));
    while(p) {
        A[i]=p->data;
        p=p->next;
        i++;
    }
    Node *q = head;
    i--;
    while(q!=NULL) {
        q->data = A[i];
        q = q->next;
        i--;
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
    Node *q = NULL;
    int A[10] = {2,3,4,5,6};
    create(A,5);
    display(head);
    //reverseLinkedList(head);
    //reverseLL_recur(q, head);
    reverseLLContent(head);
    display(head);
    return 0;
}