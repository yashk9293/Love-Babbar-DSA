// Question Link :- https://www.geeksforgeeks.org/problems/topological-sort/1
// Topological sort (Kahn's Algorithm)


class Solution {
	public:
	vector<int> topoSort(int V, vector<int> adj[]) {
	    queue<int> que;
	    vector<int> indegree(V, 0);
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
	        }
	    }
	    //3. Simple BFS
	    vector<int> result;
	    while(!que.empty()) {
	        int u = que.front();
	        result.push_back(u);
	        que.pop();
	        for(int &v : adj[u]) {
	            indegree[v]--;
	            if(indegree[v] == 0) {
	                que.push(v);
	            }
	        }
	    }
	    return result;
	}
};