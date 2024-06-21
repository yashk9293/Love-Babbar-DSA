// Question Link :- https://www.codingninjas.com/studio/problems/minimum-spanning-tree_631769
// Minimum Spanning Tree

#include <bits/stdc++.h>
using namespace std;

bool comparator(vector<int> &a, vector<int> &b) {
    return a[2] < b[2];
}

int find(int i, vector<int> &parent) {
    if(i == parent[i]) {
        return i;
    }
    return parent[i] = find(parent[i], parent);
}

void Union(int x, int y, vector<int> &parent, vector<int> &rank) {
    int x_parent = find(x, parent);
    int y_parent = find(y, parent);

    if (x_parent == y_parent) {
        return;
    }
    if(rank[x_parent] > rank[y_parent]) {
        parent[y_parent] = x_parent;
    } else if(rank[x_parent] < rank[y_parent]) {
        parent[x_parent] = y_parent;
    } else {
        parent[x_parent] = y_parent;
        rank[y_parent]++;
    }
}

int minimumSpanningTree(vector< vector<int> > &edges, int n) {
    vector<int> parent(n);
    vector<int> rank(n,0);
    for(int i=0; i<n; i++) { // Initialising parent
        parent[i] = i;
    }

    sort(edges.begin(), edges.end(), comparator);
    
    int sum = 0;
    for(auto &temp : edges) {
        int u = temp[0];
        int v = temp[1];
        int wt = temp[2];
        
        int parent_u = find(u, parent);
        int parent_v = find(v, parent);
        
        if(parent_u != parent_v) {
            Union(u, v, parent, rank);
            sum += wt;
        }
    }
    return sum;
}