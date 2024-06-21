// Floyd Warshall Algorithm - works on directed graph
// if graph is undirected, then convert it to directed.

// Question Link :- https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1

// T.C - O(V^3)
// S.C - O(V^2)

class Solution {
public:
	void shortest_distance(vector<vector<int>>&matrix) {
		int n = matrix.size();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (matrix[i][j] == -1) {
					matrix[i][j] = 1e9;
				}
			}
		}

		for(int via = 0; via < n; via++) {
            for(int i = 0; i<n; i++) {
                for(int j = 0; j<n; j++) {
                   matrix[i][j] = min(matrix[i][j], matrix[i][via] + matrix[via][j]);
                }
            }
        }

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (matrix[i][j] == 1e9) {
					matrix[i][j] = -1;
				}
			}
		}
	}
};