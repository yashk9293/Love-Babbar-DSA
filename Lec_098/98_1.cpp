// Question Link :- https://leetcode.com/problems/critical-connections-in-a-network/description/
// Critical Connections in a Network


// Brute Force
// Remove every edge one by one.
// check no. of connected components through dfs


// Optimal Solution
// T.C = O(n+e)
// S.C = O(n)
class Solution {
public:
    void dfs(int node, int parent, int &timer, vector<int> &disc, vector<int> &low, vector<vector<int>> &result, unordered_map<int, list<int>> &adjList, vector<bool> &visited) {
        visited[node] = true;
        disc[node] = low[node] = timer;
        timer++;
        for(auto neigh : adjList[node]) {
            if(neigh == parent) continue;

            if(visited[neigh] == false) {
                dfs(neigh, node, timer, disc, low, result, adjList, visited);
                low[node] = min(low[node], low[neigh]);

                // Check bridge edge
                if(low[neigh] > disc[node]) {
                    result.push_back({node, neigh});
                }
            } else {
                // Back edge found
                low[node] = min(low[node], disc[neigh]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        unordered_map<int, list<int>> adjList;
        for(int i=0; i<connections.size(); i++) {
            int u = connections[i][0];
            int v = connections[i][1];

            adjList[u].push_back(v);
            adjList[v].push_back(u); 
        }

        int timer = 0;
        vector<int> disc(n, -1);
        vector<int> low(n, -1);
        int parent = -1;
        vector<bool> visited(n, false);

        vector<vector<int>> result;
        // DFS
        for(int i=0; i<n; i++) {
            if(!visited[i]) {
                dfs(i, parent, timer, disc, low, result, adjList, visited);
            }
        }
        return result;
    }
};