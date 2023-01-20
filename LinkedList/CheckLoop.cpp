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

int checkLoop(Node *h) {
    Node *p, *q;
    p = q = h;
    do {
        p = p->next;
        q = q->next;
        q = q?q->next:q;
    } while(p && q && p!=q);
    return p==q?1:0;
}

int main() {
    
    int A[10] = {2,3,4,5,6};
    create(A,5);
    Node *p = head;
    Node *q = p;
    //next 3 lines to make a loop, remove them to remove the loop
    p = p->next->next;
    q = q->next->next->next->next;
    q->next = p;
    
    int x = checkLoop(head);
    if(x) {
        printf("Loop present\n");
    } else {
        printf("Loop not present\n");
    }
}