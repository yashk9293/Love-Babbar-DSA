// Question Link :- https://www.codingninjas.com/studio/problems/create-a-graph-and-print-it_1214551
// Creating and Printing

// Given undirected map of 'N' nodes and 'M' edges. Itis guaranteed that all the edges are 
// unique, i.e., if there is an edge from 'X' to 'Y', then there is no edge from 'Y' to 'X'.

// T.C = O(N + M)
// S.C = O(N + M)

#include <bits/stdc++.h>
using namespace std;

vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) {
    vector<vector<int>> ans(n);

    for(int i=0; i<n; i++) {
        ans[i].push_back(i);
    }

    for(int i=0; i<m; i++) {
        int u= edges[i][0];
        int v= edges[i][1];

        ans[u].push_back(v);
        ans[v].push_back(u);
    }
    return ans;
}


int main() {
    int n, m;
    cout << "Enter the number of nodes : ";
    cin >> n;
    cout << "Enter the number of edges : ";
    cin >> m;

    vector< vector<int> > edges(m, {0,0});

    for(int i=0; i<m; i++) {
        cin >> edges[i][0];
        cin >> edges[i][1];
    }

    vector< vector<int> > solution = printAdjacency(n, m, edges);

    for(auto i : solution) {
        for(auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}