#include <cstdio>
#include <iostream>
#include <stack>
using namespace std;

int A[8][8] = {
                {0,0,0,0,0,0,0,0},
                {0,0,1,1,1,0,0,0},
                {0,1,0,1,0,0,0,0},
                {0,1,1,0,1,1,0,0},
                {0,1,0,1,0,0,0,0},
                {0,0,0,1,0,0,1,1},
                {0,0,0,0,0,1,0,0},
                {0,0,0,0,0,1,0,0}
              };


void DFS(int start) {
    int visited[8] = {0};
    stack <int> s;
    printf("%d ", start);
    visited[start] = 1;
    s.push(start);
    int u,v;
    while (!s.empty()) 
    {
        u = s.top();
        s.pop();
        if(visited[u]==0) {
            cout << u << " ";
            visited[u] = 1;
        }
        for(int v=1; v<8; v++) {
            if(A[u][v]==1 && visited[v]==0) {
                s.push(v);
            }
        }
    }
}

int main()
{
    DFS(5);
}
