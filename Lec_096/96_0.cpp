// Question Link :- https://www.codingninjas.com/studio/problems/prim-s-mst_1095633
// Prim's MST

// T.C = O(N^2)
// S.C = O(N^2)

#include <bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g) {
    // create adjacency list
    unordered_map<int, vector<pair<int, int>>> adjList;
    for(int i=0; i<m; i++) {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;

        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    }

    // Initiaising the required data structures
    vector<int> key(n+1, INT_MAX);
    vector<bool> mst(n+1, false);
    vector<int> parent(n+1, -1);

    // Initialising src node
    key[1] = 0;
    parent[1] = -1;
    
    for(int i=1; i<n; i++) {
        // Calculating minimum from key vector
        int mini = INT_MAX;
        int u;
        // find min wali node
        for(int i=1; i<=n; i++) {
            if(key[i] < mini && mst[i] == false) {
                u = i;
                mini = key[i];
            }
        }
        // mark min node as true
        mst[u] = true;

        for(auto it : adjList[u]) {
            int v = it.first;
            int w = it.second;
            if(mst[v] == false && w < key[v]) {
                key[v] = w;
                parent[v] = u;
            }
        }
    }

    vector< pair<pair<int,int>, int> > answer;
    for(int i=2; i<=n; i++) {
        answer.push_back({{parent[i], i}, key[i]});
    }

    return answer;
}