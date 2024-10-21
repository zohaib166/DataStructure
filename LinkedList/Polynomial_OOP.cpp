#include <iostream>
using namespace std;

class Node {
public:
    int coef;
    int deg;
    Node *link;

    Node(int c, int d) {
        coef = c;
        deg = d;
        link = nullptr;
    }
};

class Polynomial {
public:
    Node *head = nullptr;
    void createTerm(int c, int d) {
        Node *n = new Node(c,d);
        if(head==nullptr) {
            head = n;
            return;
        }
        Node *temp = head;
        while(temp->link!=nullptr) {
            temp=temp->link;
        }

        temp->link = n;
    }

    void display() {
        Node *temp = head;
        while(temp!=nullptr) {
            cout << temp->coef << "x^" << temp->deg;
            temp = temp->link;
            if(temp!=nullptr) {
                cout << " + ";
            }
        }
        cout << endl;
    }
    friend Node* addPoly(Node *p1, Node *p2);
};

Polynomial addPoly(Polynomial p1, Polynomial p2) {
    Polynomial result;
    Node *temp1 = p1.head;
    Node *temp2 = p2.head;
    Node *tail = nullptr;

    int coef, deg;
    while(temp1 && temp2) {
        if(temp1->deg > temp2->deg) {
            coef = temp1 -> coef;
            deg = temp1 -> deg;
            temp1 = temp1 -> link;
        } else if(temp2->deg > temp1->deg) {
            coef = temp2 -> coef;
            deg = temp2 -> deg;
            temp2 = temp2 -> link;
        } else {
            coef = temp1->coef + temp2->coef;
            deg = temp1->deg;
            temp1 = temp1->link;
            temp2 = temp2->link;
        }

        Node *newNode = new Node(coef, deg);
        if(result.head == nullptr) {
            result.head = newNode;
            tail = newNode;
        } else {
            tail->link = newNode;
            tail = newNode;
        }
    }

    while(temp1) {
        Node *newNode = new Node(temp1->coef,temp1->deg);
        if(result.head == nullptr) {
            result.head = newNode;
            tail = newNode;
        } else {
            tail->link = newNode;
            tail = newNode;
        }
        temp1 = temp1->link;
    }

    while(temp2) {
        Node *newNode = new Node(temp2->coef,temp2->deg);
        if(result.head == nullptr) {
            result.head = newNode;
            tail = newNode;
        } else {
            tail->link = newNode;
            tail = newNode;
        }
        temp2 = temp2->link;
    }

    return result;
}

int main()
{
    Polynomial p1;
    p1.createTerm(2,3);
    p1.createTerm(3,2);
    p1.createTerm(4,1);
    p1.display();

    Polynomial p2;
    p2.createTerm(7,2);
    p2.createTerm(6,1);
    p2.createTerm(5,0);
    p2.display();

    Polynomial ans = addPoly(p1,p2);

    ans.display();
    return 0;
}