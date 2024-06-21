// Question Link :- https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1
// Shortest path in Directed Acyclic Graph Weighted Graph

// Approach - 1 (Dijkstra's Algorithm)
class Solution {
  public:
     vector<int> shortestPath(int n,int m, vector<vector<int>>& edges){
        unordered_map<int, vector<pair<int, int>>> adj;
        for(auto vec : edges) {
            int u = vec[0];
            int v = vec[1];
            int wt = vec[2];
            adj[u].push_back({v, wt});
        }
        vector<int> distance(n, 1e9);
        distance[0] = 0;
        queue<pair<int,int>> q;   // we can use priority queue also
        q.push({0,0});
        while(!q.empty()) {
            int d = q.front().first;
            int node = q.front().second;
            q.pop();
            for(auto it : adj[node]) {
                int v = it.first;
                int wt = it.second;
                if(d + wt < distance[v]) {
                   distance[v] = d + wt;
                   q.push({d+wt, v});
                }
            }
        }
        vector<int>ans(n, -1);
        for(int i=0; i<n; i++) {
            if(distance[i] != 1e9) {
                ans[i] = distance[i];
            }
        }
        return ans;
    }
};










// Approach - 2
class Solution {
  public:
    void solveDFS(int node, unordered_map<int, vector<pair<int, int>>> adjList, vector<int> &visited, stack<int> &st){
        visited[node] = 1;
    
        for(auto neigh: adjList[node]){
            if(visited[neigh.first]==0){
                solveDFS(neigh.first, adjList, visited, st);
            }
        }
        st.push(node);
    }
    
    stack<int> topoSort(unordered_map<int, vector<pair<int, int>>> adjList, int n){
        stack<int> st;
        vector<int> visited(n, 0);
    
        // for(int i=0; i<n; i++){
        //     if(!visited[i]){
        //         solveDFS(i, adjList, visited, s);
        //     }
        // }
        for(auto x : adjList) {
            if(visited[x.first] == 0) {
                solveDFS(x.first, adjList, visited, st);
            }
        }
        return st;
    }
    
    vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        unordered_map< int, vector<pair<int,int>> > adjList;
        for(int i=0; i<M; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            adjList[u].push_back({v,w});
        }
    
        // step1: topo sort and find linear stack ordering
        stack<int> st = topoSort(adjList, N);
    
        // step2: update distance array and output shortest distances
        vector<int> distance(N, INT_MAX);
        int src = 0;
        distance[src] = 0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            if(distance[node] != INT_MAX){
                for(auto neighbour: adjList[node]){
                    // distance[neighbour.first] = min(distance[neighbour.first], distance[node]+neighbour.second);
                    int v = neighbour.first;
                    int wt = neighbour.second;
                    if(distance[node] + wt < distance[v]) {
                        distance[v] = distance[node] + wt;
                    }
                }
            }
        }
        for(int i=0; i<N; i++){
            if(distance[i] == INT_MAX){
                distance[i] = -1;
            }
        }
        return distance;
    }
};