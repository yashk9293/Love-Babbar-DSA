// Question Link :- https://www.codingninjas.com/studio/problems/shortest-path_920528?interviewProblemRedirection=true
// Shortest Path

// Count the shortest path in undirected unweighted graph. In question wrong image has been shown.
// It is unweighted.

// T.C = O(V + E)
// S.C = O(V + E)

#include <bits/stdc++.h> 
int shortestPath(int v, int e, vector<vector<int>> &edges, int source, int dest) {
    unordered_map< int, list<int> > adj;
    // vector<vector<int>> adj(v+1);
    for(int i=0; i<e; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> visited(v+1, false);            
    vector<int> parent(v+1);

    queue<int> que;
    que.push(source);
    visited[source] = true;
    parent[source] = -1;
    for(int i = 1; i<=v; i++) {
        parent[i] = i;
    }
    while(!que.empty()) {
        int u = que.front();
        que.pop();
        for(int v : adj[u]) {
            if(!visited[v]) {
                visited[v] = true;
                parent[v] = u;
                que.push(v);
            }
        }
    }
    int cnt = 0;
    while(dest != source) {
        cnt += 1;
        dest = parent[dest];
    }
    return cnt;
}
