#include <iostream>
#include <cstdlib>
#include <queue>
#include <stack>
using namespace std;

typedef struct _node {
    struct _node* lchild;
    int data;
    struct _node* rchild;
} Node;

queue <Node*> Q;
Node *root = NULL;

void create() {
    int x;
    Node *p,*t;
    root = (Node*) malloc(sizeof(Node));
    printf("Enter the root node data: ");
    scanf("%d", &x);
    root->data = x;
    root->lchild = root->rchild = NULL;
    Q.push(root);
    while(!Q.empty()) {
        p = Q.front();
        Q.pop();
        printf("Enter the left child of %d: ", p->data);
        scanf("%d", &x);
        if(x!=-1) {
            t = (Node*) malloc(sizeof(Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            Q.push(t);
        }
        
        printf("Enter the right child of %d: ", p->data);
        scanf("%d", &x);
        if(x!=-1) {
            t = (Node*) malloc(sizeof(Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            Q.push(t);
        }
    }
}

void preorder(Node *p) {
    if(p) {
        printf("%d ", p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void iPreorder(Node *p) {
    stack <Node*> st;
    while(p!=NULL || !st.empty()) {
        if(p) {
            printf("%d ", p->data);
            st.push(p);
            p = p->lchild;
        } else {
            p = st.top();
            p = p->rchild;
            st.pop();
        }
    }
}

int main()
{
    create();
    
    iPreorder(root);

    return 0;
}

