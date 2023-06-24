#include <cstdio>
#include <stack>
#include <cstdlib>
using namespace std;

typedef struct _node {
    struct _node* left;
    struct _node* right;
    int data;
} Node;

Node *root = NULL;
stack <Node*> mystack;

void createPreBST(int pre[], int n) {
    int i = 0;
    Node *t = NULL;
    root = (Node*) malloc(sizeof(Node));
    root->data = pre[i++];
    root->left = root->right = NULL;
    Node *p = root;
    while(i<n) {
        if(pre[i] < p->data) {
            t = (Node*) malloc(sizeof(Node));
            t->data = pre[i++];
            t->left = t->right = NULL;
            p->left = t;
            mystack.push(p);
            p = t;
        } else {
            if(pre[i] > p->data && pre[i] < (mystack.empty() ? INT_MAX : mystack.top()->data)) {
                t = (Node*) malloc(sizeof(Node));
                t->data = pre[i++];
                t->left = t->right = NULL;
                p->right = t;
                p = t;
            } else {
                p = mystack.top();
                mystack.pop();
            }
        }
    }
}

void Inorder(Node *p) {

    if(p) {
        Inorder(p->left);
        printf("%d ", p->data);
        Inorder(p->right);
    }
}

int main()
{
    int pre[] = {30, 20, 10, 25, 40, 35, 45};
    int n = sizeof(pre)/sizeof(pre[0]);    
    createPreBST(pre,n);
    Inorder(root);
}