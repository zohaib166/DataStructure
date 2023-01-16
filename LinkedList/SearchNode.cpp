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

Node* search(Node *t, int key) {
    while(t) {
        if(t->data == key) {
            return t;
        }
        t = t->next;
    }
    return NULL;
}

Node* rSearch(Node *t, int key) {
    if(t==NULL) {
        return NULL;
    }
    
    if(t->data == key)
        return t;
    return rSearch(t->next, key);
        
}

int main()
{
    int A[10] = {12,3,14,5,6};
    create(A,5);
    //Node *t = search(head, 14);
    Node *t = rSearch(head, 3);
    printf("%d ", t->data);
    return 0;
}