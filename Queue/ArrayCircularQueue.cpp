#include <iostream>
using namespace std;

typedef struct myq {
    int size, front, rear, *q;
} Queue;

void init(Queue *x, int len) {
    x->size = len;
    x->rear = 0;
    x->front = 0;
    x->q = new int[x->size];
}

void nq(Queue *x, int num) {
    if((x->rear+1) % x->size == x->rear) {
        cout << "Queue is full\n";
        return;
    }
    x->rear = (x->rear+1) % x->size;
    x->q[x->rear] = num;
}

int dq(Queue *x) {    
    if(x->front==x->rear) {
        cout << "Queue is empty\n";
        return -1;
    }
    x->front = (x->front+1) % x->size;
    int temp = x->q[x->front];
    return temp;
}

int front(Queue *x) {
    if(x->front==x->rear) return -1;
    if(x->front==0) return -1;
    return x->q[(x->front+1) % x->size];
}

int rear(Queue *x) {
    if(x->front==x->rear) return -1;
    if(x->rear==-1) return -1;
    return x->q[x->rear];
}

void display(Queue *x) {
    cout << endl;
    int i = x->front+1;
    do {
        cout << x->q[i] << " ";
        i = (i+1) % x->size;
    }  while(i!=(x->rear+1)%x->size);

    cout << endl;
}

int main() {
    Queue x;
    init(&x, 10);
    
    nq(&x, 10);
    nq(&x, 20);
    nq(&x, 30);
    nq(&x, 40);
    nq(&x, 50);
    nq(&x, 60);
    nq(&x, 70);
    nq(&x, 80);
    nq(&x, 90);
    
    display(&x);

    cout << dq(&x) << endl;
    nq(&x, 100);
    cout << dq(&x) << endl;
    
    display(&x);

    cout << front(&x) << " ";
    cout << rear(&x) << endl;
}
