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

void nq_rear(Queue *x, int num) {
    if(x->rear==x->size-1) {
        cout << "Queue is full at back\n";
        return;
    }
    x->rear++;
    x->q[x->rear] = num;
}

void nq_front(Queue *x, int num) {
    if(x->front == -1) {
        cout << "Queue is full at front\n";
        return;
    }
    x->q[x->front] = num;
    x->front--;
}

int dq_front(Queue *x) {    
    if(x->front==x->rear) {
        cout << "Queue is empty\n";
        return -1;
    }   
    int temp = x->q[++x->front];
    return temp;
}

int dq_rear(Queue *x) {    
    if(x->rear==x->front) {
        cout << "Queue is empty\n";
        return -1;
    }   
    int temp = x->q[--(x->rear)];
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

void display(Queue *x) {
    int temp = x->front;
    temp++;
    while(temp != x->rear+1) {
        cout << x->q[temp] << " ";
        temp++;
    }
    cout << endl;
}

int main() {
    Queue x;
    init(&x, 10);
    
    nq_rear(&x, 5);
    nq_rear(&x, 6);
    nq_rear(&x, 7);
    nq_rear(&x, 8);
    nq_rear(&x, 9);
    nq_rear(&x, 10);

    display(&x);

    dq_front(&x);
    dq_front(&x);
    dq_front(&x);

    nq_front(&x, 12);
    nq_front(&x, 14);
    nq_front(&x, 16);

    display(&x);

    cout << front(&x) << " ";
    cout << rear(&x) << endl;
}
