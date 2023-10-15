#include <cstdio>
#define I __INT_MAX__

int cost[][8] = {
            {I, I, I, I, I, I, I, I},
            {I, I, 25, I, I, I, 5, I},
            {I, 25, I, 12, I, I, I, 10},
            {I, I, 12, I, 8, I, I, I},
            {I, I, I, 8, I, 16, I, 14},
            {I, I, I, I, 16, I, 20, 18},
            {I, 5, I, I, I, 20, I, I},
            {I, I, 10, I, 14, 18, I, I},
    };
//used to mark the covered nodes
int near[8];
//used to save MST edges
int t[2][6] = {0};

int main() {
    int i,j,k,u,v,min=I,n=8;
    //find the edge with minimum cost save it in the MST
    for(i=1;i<n;i++) {
        near[i] = I;
        for(j=i;j<n;j++) {
            if(cost[i][j] < min) {
                min = cost[i][j];
                u = i, v = j;
            }
        }
    }

    //printf("u:%d -- v:%d\n", u,v);

    t[0][0] = u; t[1][0] = v;
    near[u] = near[v] = 0;

    

    for(i=1;i<n;i++) {
        if(near[i]!=0) {
            if(cost[i][u] < cost[i][v]) {
                near[i] = u;
            } else {
                near[i] = v;
            }
        }
    }
    //printf("t[0][0]:%d -- t[1][0]:%d\n", t[0][0],t[1][0]);
    //repeat
    for(i=1; i<n-2; i++) {
        int k;
        min = I;
        for(j=1; j<n; j++) {
            if(near[j]!=0 && cost[j][near[j]] < min) {
                k = j;
                min = cost[j][near[j]];
            }
        }

        t[0][i] = k; t[1][i] = near[k];
        near[k] = 0;
       

        for(j=1;j<n;j++) {
            if(near[j]!=0 && cost[j][k] < cost[j][near[j]]) {
                near[j] = k;
            }
        }
    }

    printf("t[0][0]:%d -- t[1][0]:%d\n", t[0][0],t[1][0]);

    for(i=0;i<n-2;i++) {
        printf("(%d,%d)\n",t[0][i], t[1][i]);
    }
}