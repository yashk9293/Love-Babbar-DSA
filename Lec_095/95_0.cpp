// Question Link :- https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
// Dijkstra Algorithm (Using Priority Queue)

// Shortest Path in a weighted graph Using Dijkstras Algorithm
// It can work with both directed as well as undirected graph.

// T.C - O(E log(V)) 
// S.C - O(|E| + |V|) 

class Solution {
public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int source) {
        // pair {dist,node} where dist is the distance from source to the node. 
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> result(V, INT_MAX);
        result[source] = 0;    // Source initialised with dist=0.
        pq.push({0, source});
        while (!pq.empty()) {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for (auto &vec : adj[node]) {     // Check for all adjacent nodes
                int v = vec[0];
                int wt = vec[1];
                if (d + wt < result[v]) {
                    result[v] = d + wt;
                    pq.push({d + wt, v});      // If current distance is smaller, push it into the queue.
                }
            }
        }
        return result;
    }
};