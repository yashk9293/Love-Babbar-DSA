// BFS Traversal in Directed Graph
// Question Link :- https://www.codingninjas.com/studio/problems/bfs-in-graph_973002

// T.C = O(N + E)
// S.C = O(N + E)
// where N is vertices and E is edges

// Note :- here adj is already given in the function.

vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    int u = 0;
    vector<int>ans;
    vector<bool>visited(n, false);

    queue<int>q;
    q.push(u);
    visited[u] = true;

    while(!q.empty()){
        int u = q.front();
        q.pop();
        ans.push_back(u);

        for(auto v : adj[u]) {
            if(!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    return ans;
}