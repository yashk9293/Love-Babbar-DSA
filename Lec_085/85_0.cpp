// Adjacent List

#include<bits/stdc++.h>
using namespace std;

class Graph {
    public:
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, bool direction) {
        // direction = false -> undirected graph;
        // direction = true -> directed graph

        // create an edge from u to v
        adj[u].push_back(v);
        if(direction == false) {
            adj[v].push_back(u);
        }
    }

    void printAdjList() {
        for(auto i : adj) {
            cout << i.first << " -> ";
            for(auto j : i.second) {
                cout << j << " ";
            }
            cout << endl;
        }
    }
};


int main() {
    int n, m;
    cout << "Enter the no. of nodes : ";
    cin >> n;

    cout << "Enter the no. of edges : ";
    cin >> m;

    Graph G;

    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        G.addEdge(u, v, 0);
    }

    // Printing Graph
    G.printAdjList();

    return 0;
}

// Input :-    
// Enter the no. of nodes : 5
// Enter the no. of edges : 6
// 0 1
// 1 2
// 2 3
// 3 1
// 3 4
// 0 4

// Output :-
// 4 -> 3 0 
// 0 -> 1 4 
// 1 -> 0 2 3 
// 2 -> 1 3 
// 3 -> 2 1 4 