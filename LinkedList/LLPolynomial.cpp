#include <cstdio>
#include <cstdlib>

typedef struct _node {
    int coeff;
    int deg;
    struct _node *link;
} Node;

void create_node(Node **p, int c, int e) {
    Node *temp = NULL;
    Node *temp1 = *p;
    if(*p==NULL) {
        temp = (Node*) malloc(sizeof(Node));
        temp->coeff = c;
        temp->deg = e;
        temp->link = NULL;
        *p = temp;
    } else {
        while(temp1->link){
            temp1=temp1->link;
        }
        temp = (Node*) malloc(sizeof(Node));
        temp->coeff = c;
        temp->deg = e;
        temp->link = NULL;
        temp1->link = temp;
    }
}

void display(Node *p) {
    while(p) {
        printf("%dx^%d", p->coeff, p->deg);
        
        if(p->deg!=0 && p->link!=NULL) {
            printf(" + ");
        }
        p = p->link;
    }
    printf("\n");
}

int main() {
    Node *p1 = NULL;
    //4x^2+7
    create_node(&p1, 4, 2);
    create_node(&p1, 7, 0);
    display(p1);
    Node *p2 = NULL;
    //3x^2+5x+7
    create_node(&p2, 3, 2);
    create_node(&p2, 5, 1);
    create_node(&p2, 7, 0);
    display(p2);
}