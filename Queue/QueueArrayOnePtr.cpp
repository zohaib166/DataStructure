#include <iostream>
using namespace std;

typedef struct myq {
    int size, rear, *q;
} Queue;

void init(Queue *x, int len) {
    x->size = len;
    x->rear = -1;
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
    int temp = x->q[0];
    
    if(x->rear==-1) {
        cout << "Queue is empty\n";
        return -1;
    }
    
    for(int i=1;i<=x->rear;i++) {
        x->q[i-1] = x->q[i];
    }
    x->rear--;
    return temp;
}

int front(Queue *x) {
    if(x->rear==-1) return -1;
    return x->q[0];
}

int rear(Queue *x) {
    if(x->rear==-1) return -1;
    return x->q[x->rear];
}

int main() {
    Queue x;
    init(&x, 10);

    nq(&x, 10);
    nq(&x, 20);
    nq(&x, 30);
    nq(&x, 40);

    cout << dq(&x) << endl;
    cout << dq(&x) << endl;
    //cout << dq(&x) << endl;
    //cout << dq(&x) << endl;


    cout << front(&x) << " ";
    cout << rear(&x) << endl;
}
