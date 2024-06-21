// Question Link :- https://www.codingninjas.com/studio/problems/shortest-path-in-an-unweighted-graph_981297
// Shortest path in an unweighted graph (Love babbar)

// Print shortest path in undirected unweighted graph

// (Using BFS)
// T.C = O(N + M)
// S.C = O(N + M)

#include <bits/stdc++.h>
vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int source , int target){
    unordered_map< int, list<int> > adj;
    // vector<vector<int>> adj(n+1);
    for(int i=0; i<m; i++) {
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(n+1, false);   // declaring size is very imp, otherwise we'll get TLE
    vector<int> parent(n+1);            // declaring size is very imp, otherwise we'll get TLE
    for(int i = 1; i<=n; i++) {
        parent[i] = i;
    }
    queue<int> que;
    que.push(source);
    visited[source] = true;
    parent[source] = -1;
    while(!que.empty()) {
        int u = que.front();
        que.pop();
        for(int v : adj[u]) {
            if(!visited[v]) {
                visited[v] = true;
                que.push(v);
                parent[v] = u;
            }
        }
    }
    vector<int> path;
    while(target != source) {
        path.push_back(target);
        target = parent[target];
    }
    path.push_back(source);
    reverse(path.begin(), path.end());

    return path;
}