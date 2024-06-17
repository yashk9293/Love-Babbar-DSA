// Question Link :- same as prev ques. (https://www.codingninjas.com/studio/problems/topological-sort_982938)
// Topological Sort
// Using BFS(Kahn's Algorithm)

// T.C = O(N+E)
// S.C = O(N+E)

// visited array is not used, as it Directed Acyclic Graph (DAG)

#include <bits/stdc++.h>
using namespace std;

vector<int> topologicalSort(vector< vector<int> > &edges, int v, int e) {
    // Create adjList
    // Find all indegrees
    unordered_map<int, list<int> > adjList;
    vector<int> indegree(v,0);
    for(int i=0; i<e; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        indegree[v]++;
    }

    // for(auto i: adjList) {
    //     for(auto j : i.second) {
    //         indegree[j]++;
    //     }
    // }

    // 0 indegree walo ko push kardo
    queue<int> Q;
    for(int i=0; i<v; i++) {
        if(indegree[i] == 0) {
            Q.push(i);
        }
    }

    // do bfs
    vector<int> ans;
    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();
        ans.push_back(u);

        for(auto v : adjList[u]) {
            indegree[v]--;
            if(indegree[v] == 0) {
                Q.push(v);
            }
        }
    }
    return ans;
}

int main() {
    vector< vector<int> > edges;
    int n, m;
    cout << "Enter number of nodes : ";
    cin >> n;
    cout << "Enter number of edges : ";
    cin >> m;
    cout << "Enter edges : " << endl;
    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u,v});
    }

    vector<int> topSort = topologicalSort(edges, n, m);

    cout << "Topological Sort : ";
    for(int x : topSort) {
        cout << x << " ";
    }

    return 0;
}

// 4 4 0 1 1 2 0 3 3 2
// 6 7 0 1 0 2 1 3 2 3 3 4 3 5 4 5