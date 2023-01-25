#include<iostream>
#include <stack>
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

void display(Node *t) {
    while(t!=NULL) {
        printf("%d ", t->data);
        t = t -> next;
    }
    printf("\n");
}

int countNodes(Node *t) {
    int count=0;
    while(t!=NULL) {
        count++;
        t=t->next;
    }
    return count;
}

/**
 * @brief Method1: Find the mid node in a linked list
 * Count total nodes, traverse half of it
 * @param p 
 * @return int 
 */
int midNode1(Node *p) {
    int size = countNodes(p);
    int mid = size/2;
    int i=0;
    while (i<mid)
    {
        p=p->next;
        i++;
    }
    return p->data;
}
/**
 * @brief Method2: Find the mid node in a linked list
 * Traverse two nodes till end of the linked list, one by single node, other by two nodes
 * When the leading node reaches null, stop the lagging node and return the data pointed by it
 * @param p 
 * @return int 
 */
int midNode2(Node *p) {
    Node *q = p;
    while(p) {
        p=p->next;
        if(p)
            p=p->next;
        if(p!=NULL)
            q=q->next;
    }
    return q->data;
}

/**
 * @brief Method3: Find the mid node in a linked list
 * Add the node data/address in a stack, after all the nodes are added 
 * find the size of the stack, pop only half the stack out and find the middle node
 * @param p 
 * @return int 
 */
int midNode3(Node *p) {
    stack<int> mystck;
    while(p) {
        mystck.push(p->data);
        p=p->next;
    }
    int size = mystck.size();
    int i=0;
    int mid;
    while(i<(size/2)) {
        mystck.pop();
        mid = mystck.top();
        i++;
    }
    return mid;
}

int main()
{
    int A[10] = {2,3,4,5,6,8,11};
    create(A,7);
    display(head);
    //printf("Middle Node: %d\n", midNode1(head));
    //printf("Middle Node: %d\n", midNode2(head));
    printf("Middle Node: %d\n", midNode3(head));
    return 0;
}