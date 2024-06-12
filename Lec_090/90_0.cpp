// Question Link :- https://www.codingninjas.com/studio/problems/topological-sort_982938
// Topological Sort (Using DFS)
// It is used in Directed Acyclic Graph (DAG) only.

void solveDFS(unordered_map<int, list<int> > &adj, stack<int> &st, vector<bool> &visited, int u) {
    visited[u] = true;
    for(int& v : adj[u]) {
        if(!visited[v]) {
            solveDFS(adj, st, visited, v);
        }
    }
    st.push(u);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e) {
    unordered_map<int,list<int>> adj;
    for(int i=0; i<e; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }
    vector<bool> visited(v, false);
    stack<int> st;
    for(int i=0; i<v; i++) {
        if(!visited[i]) {
            solveDFS(adj, st, visited, i);
        }
    }
    vector<int> ans;
    while(!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}