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

Node *search(Node *p, int key) {
    Node *t = p;
    if(t!=NULL) {
        if(key == t->data) {
            return t;
        } else if(key < t->data) {
            return search(t->left, key);
        } else if(key > t->data) {
            return search(t->right, key);
        }
    }
    return NULL;
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
    root = insert(root, 30);
    insert(root, 20);
    insert(root, 35);
    insert(root, 12);
    insert(root, 40);
    inorder(root);

    if(search(root, 40) != NULL) {
        printf("\nThe key is found\n");
    } else {
        printf("\nThe Key is not found\n");
    }
}