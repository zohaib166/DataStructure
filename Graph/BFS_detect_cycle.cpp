#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

bool detectCycle(int V, vector<int> adj[], int visited[]) {
    visited[V] = 1;
    queue<pair<int, int>> q;
    q.push({V, -1});
    while(!q.empty()) {
        int node = q.front().first;
        int parentnode = q.front().second;
        q.pop();
        for(auto adjNode: adj[node]) {
            if(!visited[adjNode]) {
                visited[adjNode] = 1;
                q.push({adjNode, node});
            } else if(parentnode!=adjNode) {
                return true;
            }
        }
    }
    return false;
}

bool isCycle(int V, vector<int> adj[]) {
    int visited[V] = {0};
    for(int i=0;i<V;i++) {
        if(!visited[i]) {
            if(detectCycle(i, adj, visited)) return true;
        }
    }
    return false;
}

int main() {
    
    // V = 7, E = 7
    vector<int> adj[8] = {{}, {2,3}, {1,5}, {1,4,6}, {3}, {2,7}, {3,7}, {5,6}};
    bool ans = isCycle(8, adj);
    if (ans)
        cout << "1\n";
    else
        cout << "0\n";
    return 0;
}