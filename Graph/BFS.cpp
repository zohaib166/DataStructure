#include <cstdio>
#include <iostream>

/**Start of Implementation of queue**/
typedef struct myq {
    int size, front, rear, *q;
} Queue;

int isEmpty(Queue *x) {
    if(x->front==x->rear) {
        return 1;
    } 
    return 0;
}

void init(Queue *x, int len) {
    x->size = len;
    x->rear = -1;
    x->front = -1;
    x->q = new int[x->size];
}

void nq(Queue *x, int num) {
    if(x->rear==x->size-1) {
        std::cout << "Queue is full\n";
        return;
    }
    x->rear++;
    x->q[x->rear] = num;
}

int dq(Queue *x) {    
    if(isEmpty(x)) {
        return -1;
    }   
    int temp = x->q[++x->front];
    return temp;
}
/**End of Queue implementation**/

int A[8][8] = {
                {0,0,0,0,0,0,0,0},
                {0,0,1,1,1,0,0,0},
                {0,1,0,1,0,0,0,0},
                {0,1,1,0,1,1,0,0},
                {0,1,0,1,0,1,0,0},
                {0,0,0,1,1,0,1,1},
                {0,0,0,0,0,1,0,0},
                {0,0,0,0,0,1,0,0}
              };


void BFS(int start) {
    int visited[8] = {0};
    Queue q;
    init(&q, 7);
    printf("%d ", start);
    visited[start] = 1;
    nq(&q, start);
    int u,v;
    while (!isEmpty(&q)) 
    {
        u = dq(&q);
        for(int v=1; v<8; v++) {
            if(A[u][v]==1 && visited[v]==0) {
                printf("%d ", v);
                visited[v] = 1;
                nq(&q, v);
            }
        }
    }
    
}

int main()
{
    BFS(7);
}