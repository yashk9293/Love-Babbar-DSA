// Question Link :- https://www.codingninjas.com/studio/problems/dijkstra-s-shortest-path_920469
// Dijkstra's shortest path

#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int V, int edges, int source) {
    unordered_map<int, vector<pair<int, int>>> adj;
    // vector<vector<pair<int, int>>> adj(V);
    for(auto &it: vec){
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> result(V, INT_MAX);
    result[source] = 0;    // Source initialised with dist = 0
    pq.push({0, source});
    while (!pq.empty()) {                  // O(v)
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();                          // O(log v)
        for (auto &vec : adj[node]) {      // O(v)
            int v = vec.first;
            int wt = vec.second;
            if (d + wt < result[v]) {
                result[v] = d + wt;
                pq.push({d + wt, v});      // O(log v)
            }
        }
    }
    return result;
}