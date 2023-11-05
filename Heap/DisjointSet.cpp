#include <iostream>
using namespace std;

/**
 * This code demonstrates the (weighted) union and (collapsing) find operations on disjoint sets
 * {1,2,3,4,5,6,7,8,9}
 * 1 is the parent of 2 & 3, 5 is the parent of 6,7,8
 * 9 is alone
 */
int findParent(int u);

int set[] = {0,-3,1,1,-1,-4,5,5,5,-1};
            //  1         5

void myUnion(int u, int v) {
    //set that will have more members will become parent after union
    u = findParent(u); v = findParent(v);
    if(set[u] < set[v]) {
        set[u] = set[u] + set[v];
        set[v] = u;
    } else {
        set[v] = set[u] + set[v];
        set[u] = v;
    }
}

int findParent(int u) {
    int x = u;
    while(set[x] > 0) {
        x = set[x];
    }
    return x;
}

int main() {
    myUnion(1,5);
    for(int a: set) {
        cout << a << " ";
    }
    cout << endl;
    myUnion(1,9);
    for(int a: set) {
        cout << a << " ";
    }
    cout << endl;
    cout << findParent(9);
}