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

struct SMatrix * addSMatrix(struct SMatrix s1,struct SMatrix s2) {
    if(s1.m != s2.m || s1.n != s2.n) {
        return NULL;
    }
    int i=0,j=0,k=0; //i to traverse s1, j to traverse s2, k to traverse s3
    struct SMatrix *s3 = (struct SMatrix *) malloc(sizeof(struct SMatrix));
    s3->m = s1.m; s3->n = s1.n;
    s3->num = s1.num + s2.num;
    struct Element *e = (struct Element *) malloc(s3->num*sizeof(struct Element));
    while(i<s1.num && j<s2.num) {
        if(s1.e[i].i < s2.e[j].i) {
            s3->e[k++] = s1.e[i++];
        } else if(s1.e[i].i > s2.e[j].i) {
            s3->e[k++] = s2.e[j++];
        } else {
            if(s1.e[i].j < s2.e[j].j) {
                s3->e[k++] = s1.e[i++];
            } else if(s1.e[i].j > s2.e[j].j) {
                s3->e[k++] = s2.e[j++];
            } else {
                s3->e[k] = s1.e[i];
                s3->e[k++].x = s1.e[i++].x + s2.e[j++].x;
            }
        }
    }
    for(;i<s1.num;i++) {
        s3->e[k++] = s1.e[i];
    }
    for(;j<s2.num;j++) {
        s3->e[k++] = s2.e[j];
    }
    s3->num = k;
    return s3;
}

int main() {
    struct SMatrix s1,s2;
    create(&s1);
    create(&s2);
    display(s1); display(s2);
    struct SMatrix *s3;
    s3 = addSMatrix(s1, s2);
}