#include <iostream>
using namespace std;

struct Node {
    int data;
    int priority;
    Node *next;
};

struct priority_queue
{
    Node *front = nullptr;
    Node *rear = nullptr;
};

priority_queue pq;

Node *createNode(int data, int priority)
{
    Node *n = new Node;
    n->data = data;
    n->priority = priority;
    n->next = nullptr; // Initialize next pointer
    return n;
}

void enqueue(int data, int priority)
{
    Node *n = createNode(data, priority);
    if (pq.front == nullptr) {
        pq.front = n;
        pq.rear = n;
        return;
    }
    
    if (pq.front->priority > priority) { // Insert at the front if it has the highest priority
        n->next = pq.front;
        pq.front = n;
        return;
    }
    
    Node *prev = nullptr;
    Node *curr = pq.front;
    while (curr != nullptr && curr->priority <= priority) {
        prev = curr;
        curr = curr->next;
    }
    
    if (curr == nullptr) { // Insert at the rear
        pq.rear->next = n;
        pq.rear = n;
    } else { // Insert in the middle
        prev->next = n;
        n->next = curr;
    }
}

void display()
{
    Node *ptr = pq.front;
    if (pq.front == nullptr) {
        cout << "Queue is empty\n";
        return;
    }
    
    while (ptr != nullptr) {
        cout << ptr->data << ":" << ptr->priority << " | ";
        ptr = ptr->next;
    }
    cout << endl;
}

int main()
{
    enqueue(10, 3);
    enqueue(11, 2);
    enqueue(12, 1);
    enqueue(15, 2);
    enqueue(18, 1);
    enqueue(20, 3);
    display();

    return 0;
}
