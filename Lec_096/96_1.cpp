// Question Link :- same as previous
// Prim's Algorithm using Priority Queue

// T.C = O(M * log(N))
// S.C = O(N+M)

#include <bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g) {
    // create adjacency list
    unordered_map<int, vector<pair<int, int>>> adj;
    for(auto i : g) {
        int u = i.first.first;
        int v = i.first.second;
        int w = i.second;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

	// min heap to get node with minimum weight
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
	// let source as 1, and inititally distance of source is 0
	// {weight, node}  
	pq.push({0, 1});

    vector<int> key(n+1, INT_MAX);
    vector<int> parent(n+1, -1);
    vector<int> visited(n+1, 0);

    parent[1] = -1;
    key[1] = 0;

    while(pq.size()) {
        int w = pq.top().first;
        int node = pq.top().second;
        visited[node] = 1;
        pq.pop();

		// find node with minimum weight and to to its neighbour 
        for(auto neg: adj[node]) {
            int toGo = neg.first;
            int toGoWeg = neg.second;

			// if to react node N from key[N] update weight(key[N]) with distance from node to N
            if(visited[toGo] == 0 && toGoWeg < key[toGo]) {

                key[toGo] = toGoWeg;
                parent[toGo] = node;
                pq.push({toGoWeg, toGo});
            }
        }

    }

    vector<pair<pair<int, int>, int>> ans;
	   // loop from 2 because parent of 1 is -1 (1 is initial node)
		for(int i = 2; i <= n; i++) {
        ans.push_back({{parent[i], i}, key[i]});

    }
    return ans;
}