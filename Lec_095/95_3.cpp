// Question Link :- https://www.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1
// Shortest Path in Weighted undirected graph

// In the question, we have to find the shortest path between the vertex 1 and the vertex n,
// and the first element of the result vector should store the path weight.

class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for(auto &vec : edges) {
            int u = vec[0];
            int v = vec[1];
            int w = vec[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 1}); // {dist, node}
        vector<int> result(n+1, INT_MAX);  // vertex starting from 1 in the ques
        result[1] = 0;  // source is 1 in the ques
        vector<int> parent(n+1, -1);
		
		while(!pq.empty()) {
		    int d = pq.top().first;
		    int node = pq.top().second;
		    pq.pop();
		    for(auto &it : adj[node]) {
    			int v = it.first;
    			int wt = it.second;
    			if(d + wt < result[v]) {
    			    result[v] = d + wt;
    			    pq.push({d+wt, v});
    			    parent[v] = node;   // update the node from where it had come
    			}
		    }
		}
        vector<int> path;
        int src = 1, destNode = n;     // destination in n, in the ques
        if(result[destNode] == INT_MAX) {  // could never reached destination
            return {-1};
        }
        while(destNode != src) {
            path.push_back(destNode);
            destNode = parent[destNode];
        }
        path.push_back(1);  // last element :- source node
        path.push_back(result[n]); // first element is the  weight of the path;
        reverse(begin(path), end(path));
        
		return path;
    }
};
