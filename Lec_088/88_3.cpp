// Question Link :- https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
// Detect cycle in an undirected graph

// T.C = O(V+E)
// S.C = O(V)
class Solution {
  public:
    bool isCyclicDFS(vector<int> adj[], int u, int parent, vector<bool>& visited) {
        visited[u] = true;
        for(int &v : adj[u]) {
            if(v == parent) {
                continue;
            }
            if(visited[v]) {
                return true;
            }
            if(isCyclicDFS(adj, v, u, visited)) {
                return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        for(int i=0; i<V; i++) {
            if(!visited[i] && isCyclicDFS(adj, i, -1, visited)) {
                return true;
            }
        }
        return false;
    }
};