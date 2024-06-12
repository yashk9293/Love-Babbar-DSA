// Cycle Detection using BFS

#include <bits/stdc++.h>
using namespace std;

bool isCyclicBFS(unordered_map<int, list<int> > &adj, unordered_map<int, bool> &visited, int u) {
        queue<pair<int, int>> que;
        que.push({u, -1});
        visited[u] = true;
        while(!que.empty()) {
            pair<int, int> P = que.front();
            que.pop();
            int source = P.first;
            int parent = P.second;
            for(int &v : adj[source]) {
                if(visited[v] == false) {
                    visited[v] = true;
                    que.push({v, source});
                } else if(v != parent) {
                    return true;
                }
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
            bool ans = isCyclicBFS(adj, visited, i);
            
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
