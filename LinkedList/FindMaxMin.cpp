#include <cstdio>
#include <cstdlib>
#include <climits>

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

int findMax(Node *head) {
    Node *t = head;
    int max = head->data;
    t = t->next;
    while(t!=NULL) {
        if(t->data > max) {
            max = t->data;
            
        } 
        t=t->next;
    }
    return max;
}

int findMin(Node *head) {
    Node *t = head;
    int min = head->data;
    while(t!=NULL) {
        if(t->data <= min) {
            min = t->data;
            
        } 
        t=t->next;
    }
    return min;
}

int main()
{
    int A[10] = {2,3,4,5,6};
    create(A,5);
    //printf("%d ", findMax(head));
    printf("%d ", findMin(head));
    return 0;
}