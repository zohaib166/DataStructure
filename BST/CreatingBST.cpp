#include <cstdio>
#include <cstdlib>

typedef struct _node {
    struct _node* left;
    struct _node* right;
    int data;
} Node;

Node* insert(Node *t, int key) {
    Node *p;
    if(t==NULL) {
        p = (Node*) malloc(sizeof(Node));
        p->data = key;
        p->left = p->right = NULL;
        return p;
    } else if(key < t->data) {
        t->left = insert(t->left, key);
    } else if(key > t->data) {
        t->right = insert(t->right, key);
    }

    //key is equal to already existing element so just return
    return t;
}

Node * insertItertive(Node *p, int key) {
    Node *t=p, *r;
    if(p==NULL) {
        p = (Node*) malloc(sizeof(Node));
        p->left = p->right = NULL;
        p->data = key;
        return p;
    }
    while(t!=NULL) {
        r = t;
        if(key < t->data) {
            t = t->left;
        } else if(key > t->data) {
            t = t->right;
        } 
    }
    Node *s = (Node*) malloc(sizeof(Node));
    s->left = s->right = NULL;
    s->data = key;
    if(r->data < key) {
        r->right = s;
    } else if(r->data > key) {
        r->left = s;
    }
    return p;
}

void inorder(Node *p) {
    if(p!=NULL) {
        inorder(p->left);
        printf("%d ", p->data);
        inorder(p->right);
    }
}

int main()
{
    Node *root = NULL;
    root = insertItertive(root, 30);
    insertItertive(root, 20);
    insertItertive(root, 35);
    inorder(root);
}