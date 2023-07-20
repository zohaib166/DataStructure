#include <cstdio>
#include <cstdlib>

typedef struct _node {
    int coeff;
    int deg;
    struct _node *link;
} Node;

void create_node(Node **p, int c, int e) {
    Node *temp;
    if((*p)==NULL) {
        temp = (Node*) malloc(sizeof(Node));
        temp->coeff = c;
        temp->deg = e;
        *p = temp;
        temp->link = (Node*) malloc(sizeof(Node));
        temp = temp->link;
        temp->link = NULL;
    } else {
        temp = *p;
        while(temp->link) temp = temp->link;
        temp->coeff = c;
        temp->deg = e;
        temp->link = (Node*) malloc(sizeof(Node));
        temp = temp->link;
        temp->link = NULL;
    }
}

void display(Node *p) {
    while(p->link) {
        printf("%dx^%d", p->coeff, p->deg);
        p = p->link;
        if(p->deg>=0 && p->link!=NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

Node* addPoly(Node* p1, Node *p2) {
    Node *result = (Node*) malloc(sizeof(Node));
    Node *temp = result;
    while(p1->link && p2->link) {
        if(p1->deg > p2->deg) {
            temp->coeff = p1->coeff;
            temp->deg = p1->deg;
            p1=p1->link;
        } else if(p2->deg > p1->deg){
            temp->coeff = p2->coeff;
            temp->deg = p2->deg;
            p2=p2->link;
        } else {
            temp->coeff = p1->coeff+p2->coeff;
            temp->deg = p1->deg;
            p1=p1->link;
            p2=p2->link;
        }
        temp->link = (Node*)malloc(sizeof(Node));
        temp = temp->link;
        temp->link = NULL;
    }
    while(p1->link || p2->link) {
        if(p1->link) {
            temp->coeff = p1->coeff;
            temp->deg = p1->deg;
            p1 = p1->link;
        } 
        else {
            temp->coeff = p2->coeff;
            temp->deg = p2->deg;
            p2 = p2->link;
        }
        temp->link = (Node*)malloc(sizeof(Node));
        temp = temp->link;
        temp->link = NULL;
    }
    return result;
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

    Node *result = addPoly(p1, p2);

    display(result);
}