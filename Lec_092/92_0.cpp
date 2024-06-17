// Question Link :- https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
// Cycle Detection in Directed Graphs using BFS

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        queue<int> que;
	    vector<int> indegree(V, 0);
	    int count = 0;
	    //1. finding indegree of each node
	    for(int u = 0; u<V; u++) {
	        for(int &v : adj[u]) {
	            indegree[v]++;
	        }
	    }
	    //2. Fill que, indegree with 0
	    for(int i = 0; i<V; i++) {
	        if(indegree[i] == 0) {
	            que.push(i);
	            count++;
	        }
	    }
	    //3. Simple BFS
	    vector<int> result;   // optional here
	    while(!que.empty()) {
	        int u = que.front();
	        result.push_back(u);  // optional here
	        que.pop();
	        for(int &v : adj[u]) {
	            indegree[v]--;
	            if(indegree[v] == 0) {
	                que.push(v);
	                count++;
	            }
	        }
	    }
	    if(count == V) {  // we visited total V nodes
	        return false;  // no cycle
	    } else {
	        return true;
	    }
    }
};