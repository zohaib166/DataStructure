#include <cstdio>

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
int visited[8] = {0};
void DFS(int u) {
    int v;
    if(visited[u] == 0) {
        visited[u] = 1;
        printf("%d ", u);
        for(v = 1; v < 8; v++) {
            if(A[u][v]==1 && visited[v]==0) {
                DFS(v);
            }
        }
    }
}

int main() {
    DFS(7);
}