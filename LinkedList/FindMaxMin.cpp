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

int findMax(Node *t) {
    int max = t->data;
    t = t->next;
    while(t!=NULL) {
        if(t->data > max) {
            max = t->data;
            
        } 
        t=t->next;
    }
    return max;
}

int rFindMax(Node *t) {
    int x = 0;
    if(t==NULL) {
        return INT_MIN;
    }
    x = rFindMax(t->next);
    if(x > t->data) {
        return x;
    } else return t->data;
}

int findMin(Node *t) {
    int min = t->data;
    while(t!=NULL) {
        if(t->data <= min) {
            min = t->data;
            
        } 
        t=t->next;
    }
    return min;
}

int rFindMin(Node *t) {
    int x = 0;
    if(t==NULL) {
        return INT_MAX;
    }
    x = rFindMin(t->next);
    if(x < t->data) {
        return x;
    } else return t->data;
}

int main()
{
    int A[10] = {12,3,14,5,6};
    create(A,5);
    //printf("%d ", findMax(head));
    //printf("%d ", findMin(head));
    //printf("%d ", rFindMax(head));
    printf("%d ", rFindMin(head));
    return 0;
}