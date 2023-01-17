#include <cstdio>
#include <cstdlib>
using namespace std;

typedef struct _node
{
    int data;
    struct _node *next;
} Node;
Node *head, *last = NULL;

void insertLast(Node *t, int data) {
    Node *new_node = NULL;
    if(t==NULL) {
        new_node = (Node*)malloc(sizeof(Node));
        new_node->data = data;
        new_node->next = NULL;
        head = last = new_node;
        return;
    }
    new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    last->next = new_node;
    last = new_node;
}

void display(Node *t) {
    while(t) {
        printf("%d ", t->data);
        t=t->next;
    }
    printf("\n");
}

int main() {
    insertLast(head, 3);
    insertLast(head, 4);
    insertLast(head, 10);
    display(head);
}