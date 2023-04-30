#include <stdio.h>
#include <stdlib.h>

struct Element {
    int i,j,x;
};

struct SMatrix {
    int m, n, num;
    struct Element *e;
};

void create(struct SMatrix *s) {
    
    printf("Enter the dimensions:\n") ;
    scanf("%d%d", &s->m, &s->n);
    printf("Enter the number of elements:\n");
    scanf("%d", &s->num);
    s->e = (struct Element*) malloc(s->num * sizeof(struct Element));
    printf("Enter %d positions and elements\n", s->num);
    for(int i=0;i<s->num;i++) {
        scanf("%d%d%d", &s->e[i].i, &s->e[i].j, &s->e[i].x);
    }
}

void display(struct SMatrix s) {
    int i,j,k=0;
    printf("\n");
    for(i=0;i<s.m;i++) {
        for(j=0;j<s.n;j++) {
            if(i==s.e[k].i && j==s.e[k].j) {
                printf("%d ",s.e[k++].x);
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main() {
    struct SMatrix s;
    create(&s);
    display(s);
}