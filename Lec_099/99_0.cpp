// Question Link :- https://practice.geeksforgeeks.org/problems/articulation-point-1/1
// Articulation Points in Graphs (Tarjan's Algorithm)

// Reference - https://www.codingninjas.com/studio/library/articulation-points-in-a-graph

// Brute Force
// T.C = O(V*(V+E))
// S.C = O(V*(V+E))
// remove all vertices one by one and see if it causes the graph to become disconnected.



// Optimal Solution
// T.C = O(V + E)
// S.C = O(V)
class Solution {
  public:
    void dfs(int node, int parent, int &timer, vector<int> &disc, vector<int> &low, vector<int> &result, vector<int> adjList[], vector<bool> &visited) {
        visited[node] = true;
        disc[node] = low[node] = timer;
        timer++;
        int child = 0;

        for(auto neigh : adjList[node]) {
            if(neigh == parent) {
                continue;
            }
            if(!visited[neigh]) {
                dfs(neigh, node, timer, disc, low, result, adjList, visited);
                low[node] = min(low[node], low[neigh]);

                // Check articulation point / cut vertex
                if(low[neigh] >= disc[node] && parent != -1) {             // here condition (>=)
                    result[node]=1;
                }
                child++;
            } 
            else {
                // Back edge found
                low[node] = min(low[node], disc[neigh]);
            }
        }

        // Checking for starting node
        if(parent == -1 && child > 1) {
            result[node]=1;
        }
    }
  
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        int timer = 0;
        int parent = -1;

        vector<int> disc(V, -1);
        vector<int> low(V, -1);
        vector<bool> visited(V, false);
        vector<int> result(V, 0);

        // DFS
        for(int i=0; i<V; i++) {
            if(!visited[i]) {
                dfs(i, parent, timer, disc, low, result, adj, visited);
            }
        }

        vector<int> ans;
        for (int i = 0; i < V; i++) {
            if (result[i] == 1) {
                ans.push_back(i);
            }
        }
        
        if(ans.size()==0) return {-1} ;
        
        return ans;
    }
};