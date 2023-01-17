#include <cstdio>
#include <cstdlib>
using namespace std;

typedef struct _node {
    int data;
    struct _node *next;
} Node;

Node *head = NULL;


int countNodes(Node *t) {
    int count=0;
    while(t!=NULL) {
        count++;
        t=t->next;
    }
    return count;
}

void insertNode(Node *t, int pos, int value) {
    if(pos<0 || pos>countNodes(t)) return;
    if(pos==0 && t==NULL) {
        Node *temp = (Node*)malloc(sizeof(Node));
        temp->data = value;
        temp->next = NULL;
        head = temp;
    } else {
        for(int i=1; i<pos-1; i++) {
            t=t->next;
        }
        Node *temp = (Node*)malloc(sizeof(Node));
        temp->data = value;
        temp->next = t->next;
        t->next = temp;
    }
    
}

void display(Node *t) {
    while(t) {
        printf("%d ", t->data);
        t=t->next;
    }
    printf("\n");
}
int main() {
    int A[10];
    int size = 10;
    insertNode(head,0,99);
    insertNode(head,1,45);
    insertNode(head,1,40);
    display(head);
}