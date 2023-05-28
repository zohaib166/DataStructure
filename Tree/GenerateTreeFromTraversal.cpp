#include <cstdio>
#include <cstdlib>

typedef struct _node {
    int data;
    struct _node* left;
    struct _node* right;
} Node;

int search(int arr[], int start, int end, int value) {
    int i;
    //search an element in a given start to end range and return its index
    for(int i=start;i<=end; i++) {
        if(arr[i]==value) {
            return i;
        }
    }
    return -1;
}
/** Function to create tree, takes parameter, inorder and preorder arrays 
 * Also takes start and end index of inorder array **/
Node* buildTree(int in[], int pre[], int inStart, int inEnd) {
    //static variable to iterate through preorder array
    static int preIndex = 0;
    if(inStart>inEnd) {
        return NULL;
    }
    /*Pick current node from Preorder traversal using preIndex
    and increment preIndex*/
    Node* tnode = (Node*) malloc (sizeof(Node));
    tnode->left = tnode->right=NULL;
    tnode->data = pre[preIndex++];
    /*IF this node has no children then return*/
    if(inStart==inEnd) return tnode;

    /*Else find the index of this node in Inorder traversal*/
    int inIndex = search(in, inStart, inEnd, tnode->data);
    /*Using this index in Inorder traversal, contruct left and right 
    subtree*/
    tnode->left = buildTree(in, pre, inStart, inIndex-1);
    tnode->right = buildTree(in, pre, inIndex+1, inEnd);

    return tnode;
}

void printInorder(Node* p) {
    if(p) {
        printInorder(p->left);
        printf("%d ", p->data);
        printInorder(p->right);
    } 
}

int main() {
    int in[] = {4,2,1,5,3,6};
    int pre[] = {1,2,4,3,5,6};
    int len = sizeof(in) / sizeof(in[0]);
    Node *root = buildTree(in, pre, 0, len-1);

    printf("Inorder traversal of the constructed tree is \n");
    printInorder(root);
}