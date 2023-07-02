#include <cstdio>
#include <cstdlib>

typedef struct _node
{
    struct _node *left;
    int data;
    int height;
    struct _node *right;
} Node;

Node *root = NULL;

int NodeHeight(Node *p) {
    int hl, hr;
    hl = (p && p->left) ? p->left->height : 0;
    hr = (p && p->right) ? p->right->height : 0;
    
    return hl > hr ? hl + 1 : hr + 1;
}

int balanceFactor(Node *p) {
    int hl, hr;

    hl = (p && p->left) ? p->left->height : 0;
    hr = (p && p->right) ? p->right->height : 0;

    return hl-hr;
}

Node *LLRotation(Node *p) {
    Node *pl = p->left;
    Node *plr = pl->right;
    
    pl->right = p;
    p->left = plr;

    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);

    if(root == p) 
        root = pl;

    return pl;
}

Node *LRRotation(Node *p) {
    Node *pl = p->left;
    Node *plr = pl->right;

    pl -> right = plr -> left;
    p -> left = plr -> right;

    plr -> left = pl;
    plr -> right = p;

    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);
    plr->height = NodeHeight(plr);

    if(root == p) {
        root = plr;
    }

    return plr;
}

Node *RRRotation(Node *p) {
    return NULL;
}

Node *RLRotation(Node *p) {
    return NULL;
}

Node* insert(Node *t, int key) {
    Node *p = NULL;
    if(t==NULL) {
        p = (Node*) malloc(sizeof(Node));
        p->data = key;
        p->height = 1;
        p->left = p->right = NULL;
        return p;
    } else if(key < t->data) {
        t->left = insert(t->left, key);
    } else if(key > t->data) {
        t->right = insert(t->right, key);
    }
 
    t->height = NodeHeight(t);

    if(balanceFactor(t) == 2 && balanceFactor(t->left) == 1)
        return LLRotation(t);
    else if(balanceFactor(t) == 2 && balanceFactor(t->left) == -1)
        return LRRotation(t);
    else if(balanceFactor(t) == -2 && balanceFactor(t->right) == -1)
        return RRRotation(t);
    else if(balanceFactor(t) == -2 && balanceFactor(t->right) == 1)
        return RLRotation(t);
    
    return t;
}

void preorder(Node *p) {
    if(p!=NULL) {
        printf("%d ", p->data);
        preorder(p->left);
        preorder(p->right);
    }
}

int main()
{
    root = insert(root, 10);
    insert(root, 5);
    insert(root, 7);

    preorder(root);

    return 0;
}