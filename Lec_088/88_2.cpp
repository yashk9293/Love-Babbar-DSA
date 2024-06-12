// Cycle Detection using DFS

#include <bits/stdc++.h>
using namespace std;

bool isCyclicDFS(unordered_map<int, list<int>> &adj, int u, int parent, unordered_map<int, bool> &visited) {
    visited[u] = true;
    for(int &v : adj[u]) {
        if(v == parent) {
            continue;
        }
        if(visited[v]) {
            return true;
        }
        if(isCyclicDFS(adj, v, u, visited)) {
            return true;
        }
    }
    return false;
}

string cycleDetection(vector<vector<int> > &edges, int n, int m) {
    unordered_map<int, list<int> > adj;
    unordered_map<int, bool> visited;

    // Creating Adjacency List
    for(int i=0; i<m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=1; i<=n; i++) {
        if(visited[i] == false) {
            bool ans = isCyclicDFS(adj, i, -1, visited);        // here in DFS parent is passed in the function
            
            if(ans) {
                return "YES";
            }
        }
    }
    return "NO";
}

int main() {
    int n, m;
    vector<vector<int> > edges;
    cout << "Enter the total number of nodes : ";
    cin >> n;
    cout << "Enter total number of edges : ";
    cin >> m;

    cout << "Enter edges : " << endl;
    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u,v});
    }

    string ans = cycleDetection(edges, n, m);

    cout << "Cycle Detection Result : " << ans << endl;

    return 0;
}