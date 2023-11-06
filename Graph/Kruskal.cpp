#include <iostream>
using namespace std;


int G[3][9] = {{1,1,2,2,3,4,4,5,5},
               {2,6,3,7,4,5,7,6,7},
               {25,5,12,10,8,16,14,20,18}
              };

int set[8] = {0,-1,-1,-1,-1,-1,-1,-1};

int included[9] = {0};

int mst[2][6] = {0};

int findParent(int u) {
    int x = u, v = 0;
    while(set[x] >= 0) {
        x = set[x];
    }
    //collapsing
    while (u!=x)
    {
        v = set[u];
        set[u] = x;
        u = v;
    }
    
    return x;
}

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

int main() {
    int i=0, j, k, n=7, e=9, min, u, v;
    for(auto x: set) {
        cout << x << " ";
    }
    cout << endl;
    while(i<n-1) {
        min = INT32_MAX;
        for(j=0; j<e; j++) {
            if(included[j]==0 && G[2][j] < min) {
                min = G[2][j];
                k=j; u = G[0][j]; v = G[1][j];
            }
        }
        int x = findParent(u);
        int y = findParent(v);
        if(x != y) {
            mst[0][i] = u;
            mst[1][i] = v;
            myUnion(x, y);
            i++;
        }
        included[k] = 1;
    }

    for(auto x: set) {
        cout << x << " ";
    }
    cout << endl;

    for(i=0; i<6; i++) {
        cout << "(" << mst[0][i] << "," << mst[1][i] << ")\n";
    }

}

