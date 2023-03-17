#include<iostream>
using namespace std;

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

//recursive traversal
void display_recur(Node *t) {
    if(t!=NULL) {
        printf("%d ", t->data);
        display_recur(t->next);
    }
}

void getReverse(Node *l, int &num) {
    if(l==NULL) {
        return;
    }
    getReverse(l->next, num);
    num = num*10+l->data;
}


//reverse traversal (recursive)
void reverse_display_recur(Node *t) {
    if(t!=NULL) {
        reverse_display_recur(t->next);
        printf("%d ", t->data);
    }
}

//Iterative traversal
void display_iter(Node *t) {
    while(t!=NULL) {
        printf("%d ", t->data);
        t = t -> next;
    }
}

int main()
{
    int A[10] = {2,3,4,5,0};
    create(A,5);
    //display_iter(head);
    //display_recur(head);
    
    return 0;
}