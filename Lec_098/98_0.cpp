// Question Link :- https://www.codingninjas.com/studio/problems/bridges-in-graph_893026
// Bridges in a Graph (Tarjan's Algorithm)

// T.C = O(n+e)
// S.C = O(n)
#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, int &timer, vector<int> &disc,
    vector<int> &low, vector<vector<int>> &result,
    unordered_map<int, list<int>> &adjList, vector<bool> &visited) {

    visited[node] = true;
    disc[node] = low[node] = timer;
    timer++;
    for(auto neigh : adjList[node]) {
        if(neigh == parent) continue;

        if(visited[neigh] == false) {
            dfs(neigh, node, timer, disc, low, result, adjList, visited);
            low[node] = min(low[node], low[neigh]);

            // Check bridge edge
            if(low[neigh] > disc[node]) {             // here condition (>)
                result.push_back({node, neigh});
            }
        } else {
            // Back edge found
            low[node] = min(low[node], low[neigh]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int n, int m) {
    // Create adjList
    unordered_map<int, list<int>> adjList;
    for(int i=0; i<m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

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
