#include <iostream>
#include <vector>
using namespace std;

vector<int> G[8];
int visited[8] = {0};

void DFS(int u) {
    if(visited[u] == 0) {
        visited[u] = 1;
        cout << u << " ";
        for(int v: G[u]) {
            if(visited[v]==0) {
                DFS(v);
            }
        }
    }
}

int main() {
    G[1].push_back(2);
    G[2].push_back(1);
    G[1].push_back(3);
    G[3].push_back(1);
    G[1].push_back(4);
    G[4].push_back(1);
    G[3].push_back(5);
    G[5].push_back(3);
    G[5].push_back(4);
    G[4].push_back(5);
    G[7].push_back(5);
    G[5].push_back(7);
    G[6].push_back(5);
    G[5].push_back(6);
    DFS(7);
    cout << endl;
}