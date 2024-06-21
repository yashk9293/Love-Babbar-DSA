// Question Link :- https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
// Dijkstra Algorithm (Using Set)

// T.C - O(E log(V)) 
// S.C - O(|E| + |V|) 

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int source) {
        // pair {dist,node} where dist is the distance from source to the node. 
        set<pair<int, int>> st;
        vector<int> result(V, INT_MAX);
        result[source] = 0;    // Source initialised with dist = 0
        st.insert({0, source});
        while (!st.empty()) {
            auto &it = *(st.begin());     // Fetching top pair
            int d = it.first;
            int node = it.second;
            st.erase(it);
            for (auto &vec : adj[node]) {
                int v = vec[0];
                int wt = vec[1];
                if (d + wt < result[v]) {
                    if(result[v] != INT_MAX) {
                        st.erase({result[v], v});
                    }
                    result[v] = d + wt;
                    st.insert({d + wt, v});
                }
            }
        }
        return result;
    }
};

int main() {
    // Driver code.
    int V = 3, E = 3, S = 2;
    vector<vector<int>> adj[V];
    vector<vector<int>> edges;
    vector<int> v1{1, 1}, v2{2, 6}, v3{2, 3}, v4{0, 1}, v5{1, 3}, v6{0, 6};
    int i = 0;
    adj[0].push_back(v1);
    adj[0].push_back(v2);
    adj[1].push_back(v3);
    adj[1].push_back(v4);
    adj[2].push_back(v5);
    adj[2].push_back(v6);

    Solution obj;
    vector<int> res = obj.dijkstra(V, adj, S);

    for (int i = 0; i < V; i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}