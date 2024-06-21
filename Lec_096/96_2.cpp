// Question Link :- https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1
// Minimum Spanning Tree (codestorywithMIK)

class Solution {
	public:
	typedef pair<int, int> P;
	// Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0,0});
        vector<bool> inMST(V, false);
        int sum = 0;
        while(!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            int wt = p.first;
            int node = p.second;
            if(inMST[node] == true) {
                continue;
            }
            inMST[node] = true; // added to mst
            sum += wt;
            for(auto &tmp : adj[node]) {
                int neighbor = tmp[0];
                int neighbor_wt = tmp[1];
                
                if(inMST[neighbor] == false) {
                    pq.push({neighbor_wt, neighbor});
                }
            }
        }
        return sum;
    }
};