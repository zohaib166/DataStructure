#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>

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

void inorder(Node *p) {
    if(p) {
        inorder(p->left);
        printf("%d ", p->data);
        inorder(p->right);
    }
}

void preorder(Node *p) {
    if(p) {
        printf("%d ", p->data);
        preorder(p->left);
        preorder(p->right);
    }
}

void postorder(Node *p) {
    if(p) {
        postorder(p->left);
        postorder(p->right);
        printf("%d ", p->data);
    }
}

void iPreorder(Node *p) {
    stack <Node*> q;
    while(p!=nullptr || !q.empty()) {
        if(p!=NULL) {
            printf("%d ", p->data);
            q.push(p);
            p = p->left;
        } else {
            p = q.top();
            p = p->right;
            q.pop();
        }
    }
}

void iInorder(Node *p) {
    stack <Node*> q;
    while(p!=nullptr || !q.empty()) {
        if(p!=NULL) {
            q.push(p);
            p = p->left;
        } else {
            p = q.top();
            printf("%d ", p->data);
            p = p->right;
            q.pop();
        }
    }
}

void iPostorder(Node *p) {
    stack <Node*> st;
    while (true) {
        while (p) {
            st.push(p);
            st.push(p);
            p = p->left;
        }
        if (st.empty())
            return;
        p = st.top();
        st.pop();
        if (!st.empty() && st.top() == p)
            p = p->right;
        else {
            printf("%d ", p->data);
            p = NULL;
        }
    }
}

int main() {
    create();
    iPostorder(root);
}