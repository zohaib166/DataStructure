#include <iostream>
#include <queue>

using namespace std;

typedef struct _node {
    struct _node *left;
    int data;
    struct _node *right;
} Node;

Node *root = NULL;
queue <Node*> tq;

void create() {
    int num;
    Node *p, *temp;
   
    printf("Enter the data for root: ");
    scanf("%d", &num);
    root = (Node*) malloc (sizeof(Node));
    root->data = num;
    root->left = root->right = NULL;
    //push root address to queue
    tq.push(root);
    while(!tq.empty()) {
        //access front of queue
        p = tq.front();
        //remove it from the queue
        tq.pop();
        printf("Enter left child of %d: ", p->data);
        scanf("%d", &num);
        if(num!=-1) {
            temp = (Node*) malloc (sizeof(Node));
            temp->data = num;
            temp->left = temp->right = NULL;
            p->left = temp;
            tq.push(temp);
        }
        
        printf("Enter right child of %d: ", p->data);
        scanf("%d", &num);
        if(num!=-1) {
            temp = (Node*) malloc (sizeof(Node));
            temp->data = num;
            temp->left = temp->right = NULL;
            p->right = temp;
            tq.push(temp);
        }
    }
}

void levelOrder(Node *p) {
    queue <Node*> treeQ;
    printf("%d ", p->data);
    treeQ.push(p);
    while(!treeQ.empty()) {
        p = treeQ.front();
        treeQ.pop();
        if(p->left) {
            printf("%d ", p->left->data);
            treeQ.push(p->left);
        }
        if(p->right) {
            printf("%d ", p->right->data);
            treeQ.push(p->right);
        }
    }
}

int main() {
    create();
    levelOrder(root);
}