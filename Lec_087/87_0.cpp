// Question Link :- https://www.codingninjas.com/studio/problems/dfs-traversal_630462
// DFS Traversal (undirected and disconnected graph)

#include <bits/stdc++.h>

void dfs_traversal(unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited, vector<int> &component, int u) {
    visited[u] = true;
    component.push_back(u);
    for(auto v : adjList[u]) {
        if(!visited[v]) {
            dfs_traversal(adjList, visited, component, v);
        }
    }
}

vector< vector<int> > depthFirstSearch(int V, int E, vector< vector<int> > &edges) {
    // prepare adjList
    unordered_map<int, list<int>> adjList;
    for(int i=0; i<edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<vector<int>> ans;
    unordered_map<int, bool> visited;

    // for all nodes call DFS, if not visited
    for(int i=0; i<V; i++) {  // disconnected graph
        if(!visited[i]) {
            vector<int> component;
            dfs_traversal(adjList, visited, component, i);
            ans.push_back(component);
        }
    }
    return ans;
}