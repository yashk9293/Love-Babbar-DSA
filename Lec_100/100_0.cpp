// Question Link :- https://www.codingninjas.com/studio/problems/count-strongly-connected-components-kosaraju-s-algorithm_1171151
// Count Strongly Connected Components (Kosaraju’s Algorithm)

// T.C = O(V + E)
// S.C = O(V + E)

#include<bits/stdc++.h>

void topoSort(int node, vector<bool> &visited, stack<int> &st, unordered_map<int, list<int>> &adjList) {
    visited[node] = true;
    for(int neigh : adjList[node]) {
        if(!visited[neigh]) {
            topoSort(neigh, visited, st, adjList);
        }
    }
    st.push(node);
}

void revDFS(int node, vector<bool> &visited, unordered_map<int, list<int>> &transpose) {
    visited[node] = true;
    for(int neigh : transpose[node]) {
        if(!visited[neigh]) {
            revDFS(neigh, visited, transpose);
        }
    }
}

int stronglyConnectedComponents(int n, vector<vector<int>> &edges) {
    // Create adjList
    unordered_map<int, list<int>> adjList;
    for(int i=0; i<edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
    }

    // Topoplogical Sort
    stack<int> st;
    vector<bool> visited(n, false);
    
    for(int i=0; i<n; i++) {
        if(!visited[i]) {
            topoSort(i, visited, st, adjList);
        }
    }

    // Transpose Graph
    unordered_map<int, list<int>> transpose;
    for(int i=0; i<n; i++) {
        visited[i] = false;             // visited is changed in topological sort, so we have to make sure to rechange it to original form (all false)
        for(int neigh : adjList[i]) {
            transpose[neigh].push_back(i);
        }
    }

    // DFS call on topological sort
    int count = 0;
    while(!st.empty()) {
        int top = st.top();
        st.pop();

        if(!visited[top]) {
            count++;
            revDFS(top, visited, transpose);
        }
    }
    return count;
}