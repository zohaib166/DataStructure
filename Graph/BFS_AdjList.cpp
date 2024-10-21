#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> G[8];

void BFS(int start) {
    int visited[8] = {0};
    queue<int> q;
    cout << start << " ";
    visited[start] = 1;
    q.push(start);
    int u,v;
    while (!q.empty()) 
    {
        u = q.front();
        q.pop();
        for(int v: G[u]) {
            if(visited[v]==0) {
                cout << v << " ";
                visited[v] = 1;
                q.push(v);
            }
        }
    }
    
}

int main()
{
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
    BFS(7);

    cout << endl;
}