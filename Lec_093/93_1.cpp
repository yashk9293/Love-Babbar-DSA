// Question Link :- https://www.codingninjas.com/studio/problems/shortest-path_920528?interviewProblemRedirection=true
// Count Shortest Path in undirected unweighted graph from given src to dest


// In question wrong image has been shown. It is unweighted.



// Approach - 1 (Floyd Warshell Algorithm) [Brute Force]
// Time Complexity: O(V^3)
// Space Complexity: O(V^2)
int shortestPath(int v, int e, vector<vector<int>> &edges, int src, int dest) {
    vector<vector<int>> adj(v+1, vector<int>(v + 1, 1000000000));   // as we have to choose minimum so we are taking maximum, else not taking it will lead to zero
    for(int i=0; i<e; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    // Setting dist[index][index] as 0 as the distance between same vertices is 0.
    for(int i=1; i<v+1; i++) {
        adj[i][i] = 0;
    }

    for(int via=1; via <= v; via++) {
        for(int i=1; i <= v; i++) {   // The variables i and j for traversing all possible pairs
            for(int j = 1; j <= v; j++) {
                adj[i][j] = min(adj[i][j], adj[i][via] + adj[via][j]);
            }
        }
    }
    return adj[src][dest];
}




// Approach - 2 (Using BFS) [Preferred]
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
    vector<int> parent(v+1, -1);

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
