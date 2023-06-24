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

int height(Node *p) {
    if(p==NULL) return NULL;
    int x,y;
    x = height(p->left);
    y = height(p->right);
    return x>y?x+1:y+1;
}

Node * InPre(Node *p) {
    while(p && p->right) {
        p = p->right;
    }
    return p;
}

Node * InSucc(Node *p) {
    while(p && p->left) {
        p = p->left;
    }
    return p;
}

Node *deleteNode(Node *p, int key) {
    Node *q = NULL;
    
    if(p==NULL) return NULL;
    if(p->left==NULL && p->right==NULL) {
        free(p);
        return NULL;
    }
    if(key < p->data) {
        p->left = deleteNode(p->left, key);
    } else if(key > p->data) {
        p->right = deleteNode(p->right, key);
    } else {
        if(height(p->left) > height(p->right)) {
            q = InPre(p->left);
            p->data = q->data;
            p->left = deleteNode(p->left, q->data);
        } else {
            q = InSucc(p->right);
            p->data = q->data;
            p->right = deleteNode(p->right, q->data);
        }
    }

    return p;
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

    deleteNode(root, 35);

    printf("\n");
    inorder(root);

    if(search(root, 40) != NULL) {
        printf("\nThe key is found\n");
    } else {
        printf("\nThe Key is not found\n");
    }
}