// Question Link :- https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
// Detect cycle in an undirected graph using BFS

// T.C = O(V+E)
// S.C = O(V)
class Solution {
  public:
    bool isCyclicBFS(vector<int> adj[], int u, vector<bool>& visited) {
        queue<pair<int, int>> que;
        que.push({u, -1});
        visited[u] = true;
        while(!que.empty()) {
            pair<int, int> P = que.front();
            que.pop();
            int source = P.first;
            int parent = P.second;
            for(int &v : adj[source]) {
                if(visited[v] == false) {
                    visited[v] = true;
                    que.push({v, source});
                } else if(v != parent) {
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        for(int i=0; i<V; i++) {
            if(!visited[i] && isCyclicBFS(adj, i, visited)) {
                return true;
            }
        }
        return false;
    }
};