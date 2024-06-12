// BFS Traversal in Undirected and disconnected Graph

// T.C = O(N + E)
// S.C = O(N + E)
// where N is vertices and E is edges

#include<bits/stdc++.h>
using namespace std;

void bfs_traversal(unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited, vector<int> &ans, int u) {
    queue<int> Q;
    Q.push(u);
    visited[u] = true;
    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();
        ans.push_back(u);

        for(auto v : adjList[u]) {
            if(!visited[v]) {
                Q.push(v);
                visited[v] = true;
            }
        }
    }
}

vector<int> BFS(int vertex, vector< pair<int, int> > edges) {
    // Creating Adjacency List
    unordered_map<int, list<int>> adjList;
    for(int i=0; i< edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<int> ans;
    unordered_map<int, bool> visited;

    // Travesing all components of a graph
    for(int i=0; i<vertex; i++) {
        if(!visited[i]) {
            bfs_traversal(adjList, visited, ans, i);
        }
    }

    return ans;
}