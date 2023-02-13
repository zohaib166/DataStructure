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

//count all nodes
int countNodes(Node *p) 
{
    if(p) {
        return countNodes(p->left) + countNodes(p->right) + 1;
    } else {
        return 0;
    }
}

//count leaf nodes

int countLeaf(Node *p) {
    int x, y;
    if(p) {
        x = countLeaf(p->left);
        y = countLeaf(p->right);
        if(p->left==NULL && p->right==NULL) {
            return x+y+1;
        } else {
            return x+y;
        }
    }
    return 0;
}

//count nodes with degree 2
int countDeg2(Node *p) {
    int x, y;
    if(p) {
        x = countDeg2(p->left);
        y = countDeg2(p->right);
        if(p->left!=NULL && p->right!=NULL) {
            return x+y+1;
        } else {
            return x+y;
        }
    }
    return 0;
}

//count internal nodes, nodes with degree 1 or 2
int countInternal(Node *p) {
    int x, y;
    if(p) {
        x = countInternal(p->left);
        y = countInternal(p->right);
        if(p->left!=NULL || p->right!=NULL) {
            return x+y+1;
        } else {
            return x+y;
        }
    }
    return 0;
}

int countDeg1(Node *p) {
    int x, y;
    if(p) {
        x = countInternal(p->left);
        y = countInternal(p->right);
        //p->left && !p->right || p->right && !p-left
        if(p->left !=NULL ^ p->right!=NULL) {
            return x+y+1;
        } else {
            return x+y;
        }
    }
    return 0;
}

int height(Node *p) {
    int x=0, y=0;
    if(p==0) {
        return 0;
    } 
    x = height(p->left);
    y = height(p->right);
    if(x>y) {
        return x+1;
    } else {
        return y+1;
    }
}


int main() {
    create();
    //cout << countNodes(root) << endl;
    //cout << height(root) << endl;
    //cout << countLeaf(root) << endl;
    //cout << countDeg2(root) << endl;
    cout << countDeg1(root) << endl;

}