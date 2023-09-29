#include <iostream>
using namespace std;

typedef struct myq {
    int size, front, rear, *q;
} Queue;

void init(Queue *x, int len) {
    x->size = len;
    x->rear = -1;
    x->front = -1;
    x->q = new int[x->size];
}

void nq(Queue *x, int num) {
    if(x->rear==x->size-1) {
        cout << "Queue is full\n";
        return;
    }
    x->rear++;
    x->q[x->rear] = num;
}

int dq(Queue *x) {    
    if(x->front==x->rear) {
        cout << "Queue is empty\n";
        return -1;
    }   
    int temp = x->q[++x->front];
    return temp;
}

int front(Queue *x) {
    if(x->front==x->rear) return -1;
    return x->q[x->front+1];
}

int rear(Queue *x) {
    if(x->front==x->rear) return -1;
    if(x->rear==-1) return -1;
    return x->q[x->rear];
}

int main() {
    Queue x;
    init(&x, 10);
    nq(&x, 10);
    nq(&x, 20);
    nq(&x, 30);

    cout << dq(&x) << endl;
    cout << dq(&x) << endl;
    cout << dq(&x) << endl;

    cout << front(&x) << " ";
    cout << rear(&x) << endl;
}
